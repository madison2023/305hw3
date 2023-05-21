// Rachel Madison creates feed which is collection of posts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "feed.h"
#include "post.h"

/// Creates a new (empty) feed
feed* create_feed() {
    feed* myFeed = NULL;
    return myFeed; //???
}

/// Adds a post to the feed.
/// * add_post should maintain the property that the feed is sorted in descending
///   order by number of likes (the most-liked post is first, the least-liked post
///   last)
/// Returns pointer to added post on success, NULL if f or p is NULL
feed* add_post(feed** f, post* p) {
    if (f == NULL || p == NULL) {
        return NULL;
    }
        //creating newListNode which is the new post that will be returned
        feed *newListNode = malloc(sizeof(**f));
        newListNode->first = *p;
    
    //case if the feed is empty (adding to the beginning)
    if (*f == NULL) {
            *f = newListNode;
            newListNode->next = NULL;
            return newListNode;
    }
    //case if new post has more likes than the previous most liked post (the one at the beginning)
    else if (p->likes > (*f)->first.likes) {
            feed *temp = *f;
            *f = newListNode;
            newListNode->next = temp;
            return newListNode;
        }
    //the case where the new post has to be inserted between two posts
    else {
        //keeping track of the previous node and the one we are currently on
        feed * prevNode = *f;
        feed * currNode = (*f)->next;
        while (currNode != NULL) {
                //checks for first post that the new post has more likes than
                if (p->likes > currNode->first.likes) {
                    //puts that post in the correct place in the list
                    prevNode->next = newListNode;
                    newListNode->next = currNode;
                    return newListNode;
                }
                
            //updates previous node and current node so that we can go through the rest of the list if the if statement doesn't get hit
            prevNode = currNode;
            currNode = currNode->next;
        }
        //inserting at the end of the list
        prevNode->next = newListNode;
        newListNode->next = NULL;
        return newListNode;
    }
}

/// Deletes all posts by the provided author from f.
/// Returns the number of posts deleted (may be zero) on success,
/// or -1 if f or author is NULL
int delete_posts(feed** f, char* author) {
    feed * prevNode = *f;
    feed * currNode = (*f)->next;
    
    
    int numDeleted = 0;
    
    if (f == NULL || author == NULL) {
        return -1;
    }
    
    while (currNode != NULL){
        if (strncmp(prevNode->first.author, author, strlen(author)) == 0) {
            feed * temp = *f;
            
            
            *f = prevNode->next;
            
            
            free(temp);
            numDeleted++;
        }
        else if (strncmp(currNode->first.author, author, strlen(author)) == 0) {
            feed * temp = currNode;
            prevNode->next = currNode->next;
            numDeleted++;
            free(temp);
        }
        else if (currNode->next == NULL && strncmp(currNode->first.author, author, strlen(author)) == 0) {
                prevNode->next = NULL;
                //free(currNode);
                numDeleted++;
        }
        //updating previous and current node so we can go through whole list
        prevNode = currNode;
        currNode = currNode->next;
        
    }
    
    return numDeleted;
}

/// Prints the feed to stdout
void print_feed(feed* f) {
    if (f == NULL) {
        return;
    }
    
    while (f != NULL) {
        print_post(&(f->first));
        f = f->next;
        for (int i = 0; i < 50; i++) {
            printf("-");
        }
        printf("\n");
    }
}

/// Frees the memory for a particular feed
void free_feed(feed* f) {
    while(f != NULL) {
        free(&(f->first));
        f = f->next;
    }
    free(f);
}
