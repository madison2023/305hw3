/* CS 305, Fall 2020 Homework 3
 * author: Aaron Moss
 * 
 * Creates feeds and posts and tests them.
 *
 * Compile with command:
 *   make feed
 *
 * Run with command:
 *   ./feed
 */

#include <stdio.h>
#include "feed.h"
#include "post.h"

/* prototypes */
void run_test();

/* left off command-line parameters because unused for this program 
 */
int main() {
    run_test();
}

/* runs a test, creating feeds and adding/deleting posts
 * DO NOT EDIT THIS FUNCTION; add your own tests in separate 
 * functions
 */
void run_test() {
    // create two feeds
    feed* maria = create_feed();
    feed* james = create_feed();

    // set up some posts to add to both feeds (using values for 
    // more straightforward copying)
    post post0 = create_post("Aaron Moss", 50, "Welcome to CS 305!");
    post post1 = create_post("Aaron Moss", 5, "Java is fun!");
    post post2 = create_post("Aaron Moss", 25, 
        "I love data structures!");
    post post3 = create_post("Maria Nieto", 16, 
        "Is Dr. Moss always so enthusiastic?");
    post post4 = create_post("James Hall", 5, 
        "Can I get some help with arrays?");
    post post5 = create_post("Youngster", 128, 
        "I like shorts! They're comfy and easy to wear!");
    post post6 = create_post("Patrick Stewart", 1024, "Make it so!");
    post post7 = create_post("Jane Austen", 20, 
        "It is a truth universally acknowledged...");
    
    // add posts to both feeds
    add_post(&maria, &post0);
    add_post(&maria, &post1);
    add_post(&maria, &post2);
    add_post(&maria, &post4);
    add_post(&maria, &post6);

    add_post(&james, &post0);
    add_post(&james, &post1);
    add_post(&james, &post2);
    add_post(&james, &post3);
    add_post(&james, &post5);
    add_post(&james, &post7);

    // James unfollows Youngster
    delete_posts(&james, "Youngster"); 
    // display feeds
    printf("\n# Maria's Feed #\n\n");
    print_feed(maria);
    printf("\n# James' Feed #\n\n");
    print_feed(james);

    // free memory
    free_feed(maria);
    free_feed(james);
}
