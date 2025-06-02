# Cube_3D – 42 Team-Project
**About:**<br/>
Cub3D is a small 3D game engine made with C and MiniLibX.<br/>
It renders a first-person view using raycasting, like old-school games (e.g. Wolfenstein 3D).<br/>
You learn about graphics, raycasting, 2D-to-3D projection, and event handling.<br/>

**Team:**<br/>
This was a group project done together with **[MM1132](https://github.com/MM1132)**.<br/>

**My Part:**
- Map parsing
- Raycasting (3D rendering logic)
- 3D model of the map
- Adding wall textures
- Open/close door logic
- Map and texture validation

**MM1132’s Part:**
- Minimap:
  - Rotation
  - Fixed on player
  - Raycast display
  - View limiter
  - Zoom
- Garbage collector
- Full movement system
- Hand rendering and animation
- Mouse movement
- Wall collision detection

**Gameplay:**<br/>
Move with W, A, S, D<br/>
Turn with left/right arrow keys<br/>
Explore the map<br/>

**Features:**<br/>
Raycasting engine (2D map → 3D view)
Wall textures
MiniMap (optional/bonus)
Keyboard input and smooth movement
Door and sprite handling (bonus)
Basic floor/ceiling coloring or texturing

**Compile:**<br/>

    make

Requires MiniLibX and a Unix-like system

**Run:**<br/>

    ./cub3D assets/maps/1.cub

**Map Format (.cub):**<br/>
Must be rectangular and surrounded by walls<br/>
Defines player start position (e.g. N, S, E, W)<br/>
Includes textures, floor/ceiling colors, and 2D map layout<br/>
