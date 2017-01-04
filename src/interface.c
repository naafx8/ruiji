#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

#define COLOR_BLACK     "\x1B[0m"
#define COLOR_RED	"\x1B[31m"
#define COLOR_GREEN     "\x1B[32m"
#define COLOR_YELLOW    "\x1B[33m"
#define COLOR_BLUE	"\x1B[34m"
#define COLOR_MAGENTA   "\x1B[35m"
#define COLOR_CYAN	"\x1B[36m"
#define COLOR_WHITE     "\x1B[37m"

#ifdef COLOR
/* Given a similar_image, print out all its information */
void print_similar_image_info(struct similar_image *img)
{
	printf("source: %s%s%s\n", COLOR_BLUE, img->link, COLOR_BLACK);
	if (img->similarity >= 90)
		printf(	"similarity: %s%u%%%s\n", COLOR_GREEN, img->similarity, COLOR_BLACK);
	else if (img->similarity >= 70)
		printf(	"similarity: %s%u%%%s\n", COLOR_YELLOW, img->similarity, COLOR_BLACK);
	else
		printf(	"similarity: %s%u%%%s\n", COLOR_RED, img->similarity, COLOR_BLACK);
	printf("dimensions: %ux%u\n\n",
		img->dimensions[0], img->dimensions[1]);
}

/* A verbose message to the user when saving an image */
void image_save_toast(char *file_name, char *website_url)
{
	printf("Saving image as %s%s%s from %s%s%s...\n",
		COLOR_YELLOW, file_name, COLOR_BLACK,
		COLOR_BLUE, website_url, COLOR_BLACK);
}
#endif

#ifndef COLOR
/* Given a similar_image, print out all its information */
void print_similar_image_info(struct similar_image *img)
{
	printf("source: %s\nsimilarity: %u%%\ndimensions: %ux%u\n\n",
		img->link, img->similarity, img->dimensions[0], img->dimensions[1]);
}

void image_save_toast(char *file_name, char *website_url)
{
	printf("Saving image as %s from %s...\n",
		file_name, website_url);
}
#endif

/* Given a similar_image_db, print out all its contents */
void print_sim_results(struct similar_image_db *sim_db)
{
	for (int i = 0; i < sim_db->size; i++) {
		printf("[%d]\n", i);
		print_similar_image_info(sim_db->img_db[i]);
	}
}
