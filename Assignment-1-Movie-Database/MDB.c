/*
 *  CSC A48 - Assignment 1 starter
 * 
 *  (c) Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Hossain, MD Awsaf
 * Student Number: 1006086263
 * UTORid: hossa339
 * Your instructor's name is: Paco Estrada
 */ 

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name:
 * MD AWSAF HOSSAIN
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{
    char name[MAX_STR_LEN];
    float salary;
    struct castList_struct *next;

} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio [MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList *cast;
    
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;
    
} ReviewNode;


ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  CastList = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;
    new_node = (ReviewNode*)calloc(1, sizeof(ReviewNode));
    if (new_node == NULL){
        printf("newMovieReviewNode(): Error - there is no memory available, unable to reserve space!\n");
        return NULL;
    }
    strcpy(new_node->review.movie_title, "");
    strcpy(new_node->review.movie_studio, "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->review.cast = NULL;
    new_node->next = NULL;
    
    return(new_node);    
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *movie = NULL;
    movie = head;

    while (movie != NULL){
        if (strcmp(title, movie->review.movie_title) == 0 && strcmp(studio, movie->review.movie_studio) == 0 && year == movie->review.year){
            return movie;
        }
        movie = movie->next;
    }
    return NULL;  
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    if (findMovieReview(title, studio, year, head) != NULL){
        return head;
    }

    ReviewNode *new_movie = newMovieReviewNode();

    if (new_movie == NULL){
        printf("Error! No space in memory available!\n");
        return head;
    }
    strcpy(new_movie->review.movie_title, title);
    strcpy(new_movie->review.movie_studio, studio);
    new_movie->review.year = year;
    new_movie->review.BO_total = BO_total;
    new_movie->review.score = score;
    new_movie->next = head;
    
    return new_movie;   
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    ReviewNode *p = head;
    int review_count = 0;
    while (p != NULL){
        review_count++;
        p = p->next;
    }
    
    return review_count;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *q = findMovieReview(title, studio, year, head);

    if (q==NULL){
        printf("Sorry, no such movie exists in the database\n");
        return;
    }
    q->review.BO_total = BO_total;
    q->review.score = score;
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *pre = NULL;
    ReviewNode *tr = NULL;

    if (head == NULL){
        return NULL;
    }

    pre = head;
    tr = head->next;

    if (strcmp(head->review.movie_title, title)==0 && strcmp(head->review.movie_studio, studio)==0 && head->review.year == year){
        free(pre);
        return tr;
    }
    while (tr != NULL){
        if (strcmp(tr->review.movie_title, title) == 0 && strcmp(tr->review.movie_studio, studio) == 0 && tr->review.year == year){
            pre->next = tr->next;   
            free(tr);               
            break;                  
        }
        tr = tr->next;
        pre = pre->next;
    } 
    return head;      
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = head;
    float total_BO = 0.0;

    while (p != NULL){

        printf("%s\n", p->review.movie_title);
        printf("%s\n", p->review.movie_studio);
        printf("%d\n", p->review.year);
        printf("%f\n", p->review.BO_total);
        printf("%d\n", p->review.score);
        printf("*******************\n");

        total_BO = total_BO + p->review.BO_total;
        p = p->next;
    }

    return total_BO;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    ReviewNode *p = head;
    float total_BO = 0.0;

    while (p != NULL){
        if (strcmp(p->review.movie_studio, studio)==0){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("**********************\n");

            total_BO = total_BO + p->review.BO_total;
        }
        p = p->next;
    }

    return total_BO;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    ReviewNode *p = head;
    float total_BO = 0.0;

    while (p != NULL){
        if (p->review.score >= min_score){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("**********************\n");

            total_BO = total_BO + p->review.BO_total;
        }
        p = p->next;
    }

    return total_BO;

}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode *p = NULL;
    ReviewNode *q = NULL;

    p = head;
    while (p != NULL){

        q = p->next;
        free(p);
        p = q;
    }

    return NULL;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode *p;
    int changed = 1;
    MovieReview temp;

    if (head == NULL || head->next == NULL){
        return head;
    }

    while (changed == 1){
        changed = 0;
        p = head;

        while (p->next != NULL){
            if (strcmp(p->review.movie_title, p->next->review.movie_title) > 0){
                temp = p->review;
                p->review = p->next->review;
                p->next->review = temp;
                changed = 1;
            }

            p = p->next;

        }
    }  
        
    return head;           
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *movie = NULL;
    CastList *new_cast = NULL;
    CastList *p = NULL;
    CastList *q = NULL;

    movie = findMovieReview(title, studio, year, head);

    if (movie == NULL){
        return;
    }

    new_cast = (CastList *)calloc(1, sizeof(CastList));

    if (new_cast == NULL){
        return;
    }

    strcpy(new_cast->name, name);
    new_cast->salary = salary;
    new_cast->next = NULL;

    if (movie->review.cast == NULL){
        movie->review.cast = new_cast;
        return;
    }

    if (salary > movie->review.cast->salary){
        new_cast->next = movie->review.cast;
        movie->review.cast = new_cast;
        return;
    }

    q = movie->review.cast;
    p = movie->review.cast->next;

    while (p != NULL && p->salary >= salary){
        q = p;
        p = p->next;
    }

    q->next = new_cast;
    new_cast->next = p;
}

float movie_Earnings(ReviewNode *movie)
{
    CastList *p = NULL;
    float total_salary = 0.0;

    if (movie == NULL){
        return 0.0;
    }

    p = movie->review.cast;

    while (p != NULL){
        total_salary = total_salary + p->salary;
        p = p->next;
    }

    return movie->review.BO_total - total_salary;
}

int cast_Movie(CastList *cast, char name[MAX_STR_LEN])
{
    CastList *p = cast;

    while (p != NULL){
        if (strcmp(p->name, name) == 0){
            return 1;
        }
        p = p->next;
    }
    return 0;
}

float average_Earnings(char name[MAX_STR_LEN], ReviewNode *head)
{
    ReviewNode *p = head;
    float earnings_Total = 0.0;
    int count = 0;

    while (p != NULL){
        if (cast_Movie(p->review.cast, name) == 1){
            earnings_Total = earnings_Total + movie_Earnings(p);
            count = count + 1;
        }

        p = p->next;
    }

    if (count == 0)
    {
        return 0.0;
    }

    return earnings_Total / count;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    ReviewNode *m = NULL;
    CastList *c = NULL;
    float best_Average = 0.0;
    float current_Average = 0.0;
    int found = 0;
    char best_Name[MAX_STR_LEN];

    if (head == NULL){
        return;
    }

    strcpy(best_Name, "");

    m = head;
    while (m != NULL){
        c = m->review.cast;

        while (c != NULL){
            current_Average = average_Earnings(c->name, head);

            if (found == 0 || current_Average > best_Average){
                best_Average = current_Average;
                strcpy(best_Name, c->name);
                found = 1;
            }

            c = c->next;
        }

        m = m->next;
    }

    if (found == 1){
        printf("%s\n", best_Name);
        printf("%f\n", best_Average);
    }   

}
