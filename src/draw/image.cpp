﻿#include "image.h"

Image::Image(wstring filename) {
	unsigned char* image = SOIL_load_image(&filename[0], &width, &height, 0, SOIL_LOAD_RGBA);

	// Generate texture names
	glGenTextures(1, &texture);

	// All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//glGenerateMipmap(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}