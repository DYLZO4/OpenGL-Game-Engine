#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

// Links a VBO Attribute such as a position or color to the VAO
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
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