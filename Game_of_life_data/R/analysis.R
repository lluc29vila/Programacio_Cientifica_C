packages <- c("tidyverse", "DBI", "RPostgres", "ggpubr", "ggthemes", "ggplot2", "patchwork")
new_packages <- packages[!(packages %in% installed.packages()[, "Package"])]
if (length(new_packages)) install.packages(new_packages)

library(tidyverse)
library(DBI)
library(RPostgres)
library(ggpubr)
library(ggthemes)
library(ggplot2)
library(patchwork)

con <- dbConnect(
  RPostgres::Postgres(),
  dbname = Sys.getenv("DB_NAME"),
  host   = Sys.getenv("DB_HOST"),
  user   = Sys.getenv("DB_USER")
)
on.exit(dbDisconnect(con))

experiment <- 10

data <- dbGetQuery(con, sprintf("
  SELECT 
    topology, 
    generation, 
    AVG(celulas_vivas) AS promedio_vivas,
    STDDEV(celulas_vivas) AS sd_vivas,
    MIN(celulas_vivas) AS min_vivas,
    MAX(celulas_vivas) AS max_vivas
  FROM (
    SELECT l.run_id, l.topology, l.generation, SUM(l.state) AS celulas_vivas
    FROM life l
    JOIN runs r ON l.run_id = r.run_id
    WHERE r.experiment_id = %d
    GROUP BY l.run_id, l.topology, l.generation
  ) sub
  GROUP BY topology, generation
  ORDER BY topology, generation;
", experiment))

View(data)

data_C <- data |> filter(topology == "closed")
data_P <- data |> filter(topology == "periodic")
data_M <- data |> filter(topology == "mobius")

View(data_C)
#Función para generar graficos separados
plot_topologia <- function(df, titulo, color) {
  ggplot(df, aes(x = .data$generation, y = .data$promedio_vivas)) +
    geom_ribbon(aes(ymin = pmax(.data$promedio_vivas - .data$sd_vivas, 0),
                    ymax = .data$promedio_vivas + .data$sd_vivas),
                fill = color, alpha = 0.15) +
    geom_line(color = color, linewidth = 1.1) +
    labs(
      title = titulo,
      x = "Generación",
      y = "Promedio de células vivas"
    ) +
    theme_minimal(base_size = 13) +
    theme(
      plot.title = element_text(face = "bold", size = 14),
      panel.grid.minor = element_blank()
    )
}

p_C <- plot_topologia(data_C, "Topología: Closed", "#1b9e77")
p_P <- plot_topologia(data_P, "Topología: Periodic", "#d95f02")
p_M <- plot_topologia(data_M, "Topología: Möbius", "#7570b3")

y_max <- max(data$promedio_vivas + data$sd_vivas, na.rm = TRUE)

p_C <- p_C + ylim(0, y_max)
p_P <- p_P + ylim(0, y_max)
p_M <- p_M + ylim(0, y_max)

p_C / p_P / p_M


##Comparativa de graficos segun topologia y desviación estandar juntos

# Calcular banda ± 1 SD, evitando valores negativos
data$banda_inf <- pmax(data$promedio_vivas - data$sd_vivas, 0)
data$banda_sup <- data$promedio_vivas + data$sd_vivas

ggplot(data, aes(x = generation, y = promedio_vivas, color = topology, fill = topology)) +
  geom_ribbon(aes(ymin = banda_inf, ymax = banda_sup), alpha = 0.15, color = NA) +
  geom_line(linewidth = 1.1) +
  scale_color_brewer(palette = "Dark2") +
  scale_fill_brewer(palette = "Dark2") +
  labs(
    title = "Evolución de células vivas por topología",
    subtitle = "Promedio ± 1 desviación estándar entre simulaciones",
    x = "Generación",
    y = "Promedio de células vivas",
    color = "Topología",
    fill = "Topología"
  ) +
  theme_minimal(base_size = 14) +
  theme(
    plot.title = element_text(face = "bold", size = 16),
    plot.subtitle = element_text(color = "gray40"),
    panel.grid.minor = element_blank(),
    legend.position = "bottom",
    legend.title = element_text(face = "bold")
  )
