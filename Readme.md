<h1>3D Programming Using Core OpenGL</h1>

I am working on a 3D rendering engine using core OpenGL. The end goal of this project is to make a rendering engine that can render any 3D model/environment imported into it. I am going to use Nano GUI for the interface. GLFW is used for input handling and creating the window. GLAD for loading the OpenGL functions. 
I will be updating this repository while learning about OpenGL from <a href="https://learnopengl.com">learnopengl.com</a> and sharing the progress here through screenshots and videos. I have already created a rectangle with a texture on it. I will also briefly explain any new functions or techniques I come accross so this may be helpful for people starting off with OpenGL or graphics programming in general. 

<h2>March, 2023</h2>
Playing around with vertex attributes and shaders to change the positions of the vertices of a rectangle with texture on it. 
I find out the vertex closest to the mouse cursor's position and through a threshold value make that vertex "activated" so it can be dragged using left click. That vertex will have a black shade on it as shown in the gif below. I used <a href="https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBufferSubData.xhtml"><i>glBufferSubData</i></a> to edit the vertices data from the existing buffer. Using this I was able to edit out only the data of the vertex that I wanted to edit; leaving the others unchanged. 
</br>
</br>
<kbd><img src = "https://user-images.githubusercontent.com/31384470/224296430-42524ebb-cd66-4a74-a605-990ca8d84ee7.png" width = "341px" height = "195px">
</kbd>
</br>
</br>
The fragment shader has a vec2 uniform that is fed in the value of the closest vertex's X and Y coordinates. And using the if statement I was able to locate that vertex and modify it's color. 
</br>
</br>

![opengl1](https://user-images.githubusercontent.com/31384470/224283525-0b557706-cc7f-4983-a2e5-5eaaf77c9e8d.gif)

Added model, view and projection matrix to the project for some actual 3D. Used the glm library for the matrix operations. 
</br>

![2023-03-11 20-57-46 (online-video-cutter com)](https://user-images.githubusercontent.com/31384470/224493410-9fc0cb74-a689-45a1-84e6-b3e97515c7db.gif)

Created a cube instead of the boring plane and added some rotation to it based on mouse input. I calculate the direction vector of the cursor per frame everytime it moves. And by getting a cross product of the roll axis and the direction vector, I get the axis to rotate the cube around. Generating the following output:
</br>

![opengl3](https://user-images.githubusercontent.com/31384470/224553153-41651c69-07ef-42d4-8490-32b8307705d9.gif)

Raining cubes and some inputs for looking around and walking. 
</br>

![opengl4](https://user-images.githubusercontent.com/31384470/224553542-aed2b6ae-3850-42bd-9ddf-d92bea82b1f9.gif)

<h2>April, 2023</h2>
Took a little detour and redesigned the whole thing to a little game after finishing the very basics of OpenGL. The cube detects the color in the bottom tile takes up that color. It'll turn out to be a very basic hyper casual. 
</br>
![gameplay](https://user-images.githubusercontent.com/31384470/229128797-1c35e43c-0f18-4f9f-ae78-101c795b5005.gif)
</br>
