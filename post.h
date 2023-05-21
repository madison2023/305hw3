#pragma once

/* 
 * Defines a post type for CS 305 HW 3
 *
 * Author: Aaron Moss
 */

#define MAX_NAME_LENGTH 31
#define MAX_POST_LENGTH 255

/// post type; represents a social-media post.
typedef struct post {
    char author[MAX_NAME_LENGTH + 1];
    int likes;
    char contents[MAX_POST_LENGTH + 1];
} post;

/// creates a new post with the given fields;
/// will truncate author and contents if necessary
post create_post(char* author, int likes, char* contents);

/// prints a post to stdout
void print_post(post* p);