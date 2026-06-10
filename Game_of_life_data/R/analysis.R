####Librerias
install.packages("tidyverse")
install.packages("ggplot2")
library(tidyverse)
library(ggplot2)

####BASICS
life <- read.csv("life.csv")

head(life)

str(life)

summary(life)

life_alive <- life |> filter(state == 1)
nrow(life_alive)

#Calculo de vivas por generación
alive_per_gen <- life |>
  filter(state == 1) |>
  group_by(generation) |>
  summarise(alive_cells = n())

alive_per_gen

#Grafico de como evoluciona la población con las tres juntas
ggplot(alive_per_gen,
       aes(x = generation,
           y = alive_cells)) +
  geom_line()

#Grafico de como evolucionan por separado
alive_per_gen <- life |>
  filter(state == 1) |>
  group_by(topology, generation) |>
  summarise(alive_cells = n(), .groups = "drop")

print(alive_per_gen)

ggplot(alive_per_gen,
       aes(x = generation,
           y = alive_cells,
           color = topology)) +
  geom_line() +
  labs(
    title = "Game of Life",
    subtitle = "Comparación entre topologías",
    x = "Generación",
    y = "Células vivas",
    color = "Topología"
  )
