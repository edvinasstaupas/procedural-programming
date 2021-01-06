#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node node_s;//structure of nodes
// sarasai skaiciuojami nuo 1
void Print_list( node_s *head);
void Create_list( int n, node_s **head);
void Insert_node( int pos, int value, node_s **head);
void Delete_nodes( node_s **head);

#endif // likedList_H_INCLUDED
