#pragma once

#include "post.h"

/* 
 * Defines a feed type for CS 305 HW 3
 *
 * Author: Aaron Moss
 */

/// Feed type; represents a social-media feed.
typedef struct feed_t feed;

struct feed_t {
    post first;  // first post in feed
    feed* next;  // linked-list link to rest of feed
};

/// Creates a new (empty) feed
feed* create_feed();

/// Adds a post to the feed.
/// * add_post should maintain the property that the feed is sorted in descending 
///   order by number of likes (the most-liked post is first, the least-liked post
///   last)
/// Returns pointer to added post on success, NULL if f or p is NULL
feed* add_post(feed** f, post* p);

/// Deletes all posts by the provided author from f.
/// Returns the number of posts deleted (may be zero) on success, 
/// or -1 if f or author is NULL
int delete_posts(feed** f, char* author);

/// Prints the feed to stdout
void print_feed(feed* f);

/// Frees the memory for a particular feed
void free_feed(feed* f);