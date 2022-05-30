# Cub3d
## Description
This is kind of simple game, UI based on ray casting algorithm
## Map
Looking for the map examples in ./maps
To create you own map - make a file following next rules
- only 4 possible characters: 0 for an empty space, 1 for a wall, 2 for an item and N,S,E or W for the player’s start position and spawning orientation
- map must be closed/surrounded by walls
- except for the map content, each type of element can be separated by one or more empty line(s)
- Resolution - R 1700 900
- North texture - NO ./path_to_the_north_texture
- South texture- SO ./path_to_the_south_texture
- West texture - WE ./path_to_the_west_texture
- East texture - E ./path_to_the_east_texture
- Floor color(rgb) - F 220,100,0
- Cell color(rgb) - C 225,30,0

![preview](img/preview.png?raw=true)
![preview](img/preview2.png?raw=true)

