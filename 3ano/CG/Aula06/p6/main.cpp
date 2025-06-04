#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <vector>

#include "vector.cpp"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define push_float_vert(verts, x, y, z) {\
							             verts.push_back(x);\
										 verts.push_back(y);\
										 verts.push_back(z);\
								 		}

struct Image {
	int width;
	int height;
	int channels;
	unsigned char* data;
};

// counting frames
int lastTime;
int frame;

// mouse drag
int buttonPressed = false;
v2 initialMousePos;

// Global variables for initial camera angles during a mouse drag.
float initialAlpha;
float initialBeta;
float angle = 0;

// camera
struct cam {
	v3 P = {0, 0, 0}, L = {0, 0, 0}, U = {0, 1, 0};
	float alpha = M_PI_4, beta = M_PI_4;
	float radius = 100.0f;
};

cam camera;

// trees
#define N_TREES 1000
int treePosX[N_TREES];
int treePosY[N_TREES];
#define R 30

// teapots
#define N_ITEAPOT 10
#define RI 5
#define N_OTEAPOT 20
#define RO 20

float iteapot_angle = 0;
float oteapot_angle = 0;

// terrain
// vbos
GLuint terrainVertices;
Image terrainImage;

Image loadImage(const char* path) {
	Image img;
	img.data = stbi_load(path, &img.width, &img.height, &img.channels, 0);
	
	if (!img.data) {
		printf("Failed to load image: %s\n", path);
	} else {
		printf("Image loaded successfully!\n");
		printf("Width: %d, Height: %d, Channels: %d\n", img.width, img.height, img.channels);
	}
	return img;
}

void vboDrawPlaneTextured(std::vector<float>& verts, int planeWidth, int planeHeight, const Image& img) {
	float sx = -((float)planeWidth / 2);
	float sy = -((float)planeHeight / 2);
	float texToSpaceX = (float)planeWidth / (img.width - 1);
	float texToSpaceY = (float)planeHeight / (img.height - 1);
	
	for (int i = 0; i < img.height - 1; i++) {
		for (int j = 0; j < img.width; j++) {
			float bl_x = sx + j * texToSpaceX;
			float bl_y = sy + (img.height - 1 - (i + 1)) * texToSpaceY;
			float bl_z = ((int)img.data[((i + 1) * img.width + j) * img.channels]) * 0.2f;

			float tl_x = sx + j * texToSpaceX;
			float tl_y = sy + (img.height - 1 - i) * texToSpaceY;
			float tl_z = ((int)img.data[(i * img.width + j) * img.channels]) * 0.2f;

			push_float_vert(verts, tl_x, tl_y, tl_z);
			push_float_vert(verts, bl_x, bl_y, bl_z);
		}
	}
}

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;
	// compute window's aspect ratio
	float ratio = w * 1.0f / h;
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);

	// finally set the viewport to be the entire window
	glViewport(0, 0, w, h);
}

/*void cross (float* a, float *b, float *res) {
	res[0] = a[1] * b[2] - a[2] * b[1];
	res[1] = a[2] * b[0] - a[0] * b[2];
	res[2] = a[0] * b[1] - a[1] * b[0];
}*/

void gluLookAtV3(v3 P, v3 L, v3 U) {
	gluLookAt(P.x, P.y, P.z,
		L.x, L.y, L.z,
		U.x, U.y, U.z);
}

void setCameraPos() {
    float cx = camera.radius * cos(camera.beta) * sin(camera.alpha);
    float cy = camera.radius * sin(camera.beta);
    float cz = camera.radius * cos(camera.beta) * cos(camera.alpha);

    camera.P.x = cx + camera.L.x;
    camera.P.y = cy + camera.L.y;
    camera.P.z = cz + camera.L.z;
}

void drawObjects(){

    for(int i = 0; i < 500; i++){
        float x = (rand() % 200) - 100;
        float z = (rand() % 200) - 100;

        if(sqrt(x * x + z * z) < 35){
            continue;
        }

        glPushMatrix(); 
        glTranslatef(x, 20, z);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        glColor3f(0.6f, 0.3f, 0.0f);
        glutSolidCone(0.5,4,6,6);
        glTranslatef(0.0f, 0.0f, 2.0f);
        glColor3f(0.0f, 0.5f, 0.0f);
        glutSolidCone(2, 6, 10, 10);
        glPopMatrix();
    }
}

void renderScene(void)
{
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// set camera
	glLoadIdentity();
	setCameraPos();
	gluLookAtV3(camera.P, camera.L, camera.U);  
    srand(2);
    drawObjects();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(-90, 1, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, terrainVertices);
	glVertexPointer(3, GL_FLOAT, 0, 0);
    for (int i = 0; i < terrainImage.height - 1 ; i++) {
		glDrawArrays(GL_TRIANGLE_STRIP, (terrainImage.width) * 2 * i, (terrainImage.width) * 2);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
    
    
	frame++;
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	float dt = (currentTime - lastTime) / 1000.0f;
	if (currentTime - lastTime > 1000) {
		float fps = frame*1000.0/(currentTime-lastTime);
		char title[100];
		sprintf(title, "OpenGL Window - FPS: %.2f - DT: %.3f", fps, dt);
		glutSetWindowTitle(title);
		lastTime = currentTime;
		frame = 0;
	}

	// End of frame
	glutSwapBuffers();

	// Update lastTime to the current time for the next frame.
	lastTime = currentTime;
}

void printInfo() {
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
}



void keyPress(unsigned char key, int x, int y) {
	v3 D = camera.P - camera.L;
	v3 right = normalize(cross(camera.U, D));
	switch (key) {
		case 's':
			camera.L = camera.L - camera.U * 0.5f;
			break;
		case 'w':
			camera.L = camera.L + camera.U * 0.5f;
			break;
		case 'a':
			camera.L = camera.L - right * 0.5f;
			break;
		case 'd':
			camera.L = camera.L + right * 0.5f;
			break;
		case 'n':
			camera.alpha += 0.1;
			break;
		case 'm':
			camera.alpha -= 0.1;
			break;
		case 'z':
			camera.beta += 0.1;
			break;
		case 'x':
			camera.beta -= 0.1;
			break;
	}

	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	if (buttonPressed) {
		v2 currentMousePos = {(float)x, (float)y};
		v2 deltaMousePos = currentMousePos - initialMousePos;
		
		// Update the camera angles:
		//   - Horizontal mouse movement (delta.x) changes the azimuth (alpha)
		//   - Vertical mouse movement (delta.y) changes the elevation (beta)
		camera.alpha = initialAlpha - deltaMousePos.x * 0.005f;
		camera.beta = initialBeta + deltaMousePos.y * 0.005f;
		
		// Clamp camera.beta to keep it from flipping (e.g., between -89 and 89 degrees)
		if (camera.beta < -M_PI_2 + 0.1f) {
			camera.beta = -M_PI_2 + 0.1f;
		} else if (camera.beta > M_PI_2 - 0.1f) {
			camera.beta = M_PI_2 - 0.1f;
		}
	}
	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		// Store the initial mouse position.
		initialMousePos = {(float)x, (float)y};
		// Store the current camera angles.
		initialAlpha = camera.alpha;
		initialBeta = camera.beta;
		buttonPressed = true;
	}
	else if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
		buttonPressed = false;
	}
	else if (button == 3) {
        camera.radius *= 0.99f;
    } else if (button == 4) {
        camera.radius *= 1.01f;
    }
}

int main(int argc, char** argv)
{
	for (int i = 0; i < N_TREES; i++) {
		float randX = 0.0f;
		float randY = 0.0f;
		do {
			randX = (float)rand() / RAND_MAX * 200.f - 100.0f;
			randY = (float)rand() / RAND_MAX * 200.f - 100.0f;
		} while (randX * randX + randY * randY < R * R);
		treePosX[i] = randX;
		treePosY[i] = randY;
	}

	// put GLUT init here
	glutInit(&argc, argv);
	printInfo();

	// Set display mode (single buffer and RGBA)
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	// Set window size and position
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	// Create a window with a title
	glutCreateWindow("OpenGL Window");

	// Register display callback
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene); // to count frames
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyPress);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);

	// init GLEW
	glewInit();
	glEnableClientState(GL_VERTEX_ARRAY);

	// some OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// enter GLUTs main cycle
	setCameraPos();

	terrainImage = loadImage("../assets/terreno.jpg");
	if (!terrainImage.data) {
		return 0;
	}
	if (terrainImage.width != terrainImage.height) {
		printf("Image must be square for the terrain!\n");
		return 0;
	}

	// Create the vertex buffer for the terrain plane using the image info.
	std::vector<float> vertexB;
	// plane dimensions are separate (here, 100 by 100 units)
	vboDrawPlaneTextured(vertexB, 100, 100, terrainImage);

	glGenBuffers(1, &terrainVertices);
	glBindBuffer(GL_ARRAY_BUFFER, terrainVertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertexB.size(), vertexB.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Optionally, free the image data if no longer needed:
	// stbi_image_free(terrainImage.data);

	lastTime = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
	
	return 1;
}
