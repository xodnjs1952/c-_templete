#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "funtion.h"
template <class t1>
class Box : public GeometricObjectInterface
{
public:
	t1 x_center, y_center;
	int r;

	Box(t1  _x_center, t1  _y_center) {
		x_center = _x_center;
		y_center = _y_center;
		r = 50;
	}
	void draw()
	{
		printf("\n box \n centrer%d,%d \n length", x_center, y_center, r*2);
		/*for (int i = x_center - r; i < x_center + r; i++) {
			for (int j = y_center - r; j < y_center + r; j++) {
				drawPixel(i, j, 0.0f, 1.0f, 1.0f);
			}
		}*/
	}
};

template <class t>
class circle : public GeometricObjectInterface
{
public:
	t x_center,y_center;
	int r;

	circle(t  _x_center, t  _y_center) {
		x_center = _x_center;
		y_center = _y_center;
		r = 50;
	}
	void draw()
	{

		printf("\n circle \n centrer%d,%d \n radious", x_center, y_center, r);
		/*for (int i = x_center - r; i < x_center + r; i++) {
			for (int j = y_center - r; j < y_center + r; j++) {
				double empty_circle;
				double mouse_circle;
				empty_circle = ((double)i - x_center)*((double)i - x_center) + ((double)j - y_center)*((double)j - y_center) - (r - 5)*(r - 5);
				mouse_circle = ((double)i - x_center)*((double)i - x_center) + ((double)j - y_center)*((double)j - y_center) - r * r;
				if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
				}
			}
		}*/

	}
};

class GeometricObjectInterface
{
public:
	virtual void draw(){}
};


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		std::fill_n(pixels, width*height * 3, 1.0f);

		std::vector<GeometricObjectInterface*>object_list;
		object_list.push_back(new Box<int>(100,100));
		object_list.push_back(new circle<int>(300,300));
		for (auto itr : object_list)
			itr->draw();


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
