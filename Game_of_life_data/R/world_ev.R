# Librerías
packages <- c("tidyverse", "DBI", "RPostgres", "gganimate", "gifski")
new_packages <- packages[!(packages %in% installed.packages()[, "Package"])]
if (length(new_packages)) install.packages(new_packages)

library(tidyverse)
library(DBI)
library(RPostgres)
library(gganimate)
library(gifski)

# Conectar
con <- dbConnect(
  RPostgres::Postgres(),
  dbname = Sys.getenv("DB_NAME"),
  host   = Sys.getenv("DB_HOST"),
  user   = Sys.getenv("DB_USER")
)
on.exit(dbDisconnect(con))

# Cargar datos de una run específica
run <- 35  # Cambia por el run_id que quieras visualizar

mundo <- dbGetQuery(con, sprintf("
    SELECT generation, row_num, col_num, state
    FROM life
    WHERE run_id = %d AND topology = 'periodic'
    ORDER BY generation, row_num, col_num
", run))

# Animación
anim <- mundo |>
  mutate(state = factor(state,
                        levels = c(0, 1),
                        labels = c("Dead", "Alive"))) |>
  ggplot(aes(x = col_num, y = row_num, fill = state)) +
  geom_tile(color = "gray20", linewidth = 0.3) +
  scale_fill_manual(values = c("Dead" = "#1a1a2e", "Alive" = "#00d4aa")) +
  scale_y_reverse() +
  coord_fixed() +
  labs(
    title = "Game of Life — Run {run}",
    subtitle = "Generation: {frame_time}",
    fill = NULL
  ) +
  theme_void(base_family = "mono") +
  theme(
    plot.background  = element_rect(fill = "#0d0d1a", color = NA),
    panel.background = element_rect(fill = "#0d0d1a", color = NA),
    plot.title    = element_text(color = "#00d4aa",
                                 size = 14,
                                 hjust = 0.5,
                                 margin = margin(b = 4)),
    plot.subtitle = element_text(color = "#aaaacc",
                                 size = 11,
                                 hjust = 0.5,
                                 margin = margin(b = 8)),
    legend.position = "none"
  ) +
  transition_time(generation) +
  ease_aes("linear")

# Renderizar y guardar
animate(
  anim,
  nframes    = length(unique(mundo$generation)),
  fps        = 5,       # Velocidad: ajusta entre 2-10
  width      = 600,
  height     = 600,
  renderer   = gifski_renderer("game_of_life_run1.gif")
)