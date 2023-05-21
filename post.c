/* Implements the post type for CS 305 HW 3
 * Author: Aaron Moss
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

post create_post(char* author, int likes, char* contents) {
    post p;
    if ( author ) {
        strncpy(p.author, author, MAX_NAME_LENGTH);
        p.author[MAX_NAME_LENGTH] = '\0';
    } else {
        p.author[0] = '\0';
    }
    p.likes = likes;
    if ( contents ) {
        strncpy(p.contents, contents, MAX_POST_LENGTH);
        p.contents[MAX_POST_LENGTH] = '\0';
    } else {
        p.contents[0] = '\0';
    }
    return p;
}

void print_post(post* p) {
    if ( ! p ) return;
    printf("**%s**\n%s\n%dx <3\n", p->author, p->contents, p->likes);
}