#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO VBO, GLuint layout) {
	VBO.Bind();
	//Configure the vertex attribute so that openGL knows how to read the VBO
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	// enable the vertex attribute so that OpenGl knows how to use it 
	glEnableVertexAttribArray(layout);
	VBO.Unbind();

}

void VAO::Bind() {
	// make the vao the current object by binding it
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	
	glBindVertexArray(0);
}


void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}