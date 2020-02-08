#include<iostream>

/*
1. Insert element in LL
2. Delete nth node from LL
3. Delete given element from LL
4. Search element in LL
5. Return nth node from end in LL 
*/

class Node
{
public:
    int data;
    Node* next;
    Node* create_Node(int new_data);
};

class LinkedList : public Node
{
    LinkedList* head = nullptr;
    LinkedList** const head_ref = &head;
public:
    LinkedList(Node*);
    void push(int new_data);
    void insert(int new_data, int pos);
    void remove(int pos);
    int search_data(int some_data);
    auto at_pos(int pos);
    auto at_reverse_pos(int pos);
    void print_Linked_List();
};

Node* Node::create_Node(int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;
    return new_node;
}

LinkedList::LinkedList(Node* new_node)
{
    head = (LinkedList*)new_node;
}

void LinkedList::push(int new_data)
{
    Node* new_node = create_Node(new_data);
    new_node->next = *head_ref;
    *head_ref = (LinkedList*)new_node;
}

void LinkedList::insert(int new_data, int pos)
{
    if (pos==1)
        push(new_data);
    
    else
    {
        Node* new_node = create_Node(new_data);
        LinkedList* current = *head_ref;
        for (int i=2; current!=nullptr; i++)
        {
            if (pos==i)
            {
                new_node->next = current->next;
                current->next = new_node;
                break;
            }

            current = (LinkedList*)current->next;
        }
    }
}

void LinkedList::remove(int pos)
{
    LinkedList* current = head;
    if (pos==1)
    {
        *head_ref = (LinkedList*)head->next;
        free(current);
    }
    
    else
    {
        for (int i=2; current!=nullptr; i++)
        {
            if (pos==i)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            current = (LinkedList*)current->next;
        }
    }
}

int LinkedList::search_data(int some_data)
{
    LinkedList* current = *head_ref;
    for(int i=1; current!=nullptr; i++)
    {
        if (some_data == current->data)
        {   
            std::cout << "Position: " << i << std::endl;
            return i;
        }
        
        current = (LinkedList*)current->next;
    }

    std::cout << "Data not found!" << std::endl;
    return -1;
}

auto LinkedList::at_pos(int pos)
{
    LinkedList* current = *head_ref;
    for (int i=1; current!=nullptr; i++)
    {
        if (pos==i)
        {
            std::cout << "Data found: " << current->data << std::endl;
            return current->data;
        }

        current = (LinkedList*)current->next;
    }

    std::cout << "Position invalid" << std::endl;
    return -1;
}

auto LinkedList::at_reverse_pos(int pos)
{
    LinkedList* main_ptr = head;
    LinkedList* ref_ptr = head;

    for (int i=0; i<pos; i++)
    {
        ref_ptr = (LinkedList*)ref_ptr->next;
        if (ref_ptr == nullptr)
        {
            std::cout << "Position larger than length of linked-list." << std::endl;
            return -1;
        }
    }

    while (ref_ptr!=nullptr)
    {
        main_ptr = (LinkedList*)main_ptr->next;
        ref_ptr = (LinkedList*)ref_ptr->next;
    }
    std::cout << "Data found: " << main_ptr->data << std::endl;
    return main_ptr->data;
}


void LinkedList::print_Linked_List()
{
    LinkedList* current = *head_ref;
    while(current!=nullptr)
    {
        std::cout << current->data << " ";
        current = (LinkedList*)current->next;
    }
    std::cout << std::endl;
}


int main()
{
    // Create a linked list
    Node n;
    Node* new_node = n.create_Node(10);
    LinkedList l(new_node);
    
    // Add a new node
    l.push(20);
    l.push(40);
    l.insert(30,1);
    l.print_Linked_List();
    l.remove(3);
    l.print_Linked_List();
    int position = l.search_data(10);
    auto data = l.at_pos(1);
    auto data1 = l.at_reverse_pos(2);

    return 0;
}