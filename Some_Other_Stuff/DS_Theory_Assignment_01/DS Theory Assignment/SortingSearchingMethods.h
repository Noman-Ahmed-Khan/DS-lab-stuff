#ifndef SORTING_SEARCHING_METHODS_H
#define SORTING_SEARCHING_METHODS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DynamicArray.h"
#include "ServiceRequest.h"
#include "AgentService.h"

using namespace std;

template <typename T1, typename T2>
class Pair{
private:
    T1 first;  
    T2 second; 

public:
    Pair();
    Pair(T1 _first,T2 _second);
    void set_First(T1 first);
    void set_Second(T2 second);
    T1 get_First();
    T2 get_Second();
};

class Config {
private:
    DynamicArray<Pair<string,string>> key_value;
    void trim(string& str); 

public:
    void load(const string& filename);
    DynamicArray<Pair<string,string>> get_keyValuePair();

};
class SortingSearchingAlgorithm{
private:
    string sortingAlgorithm;
    string searchingAlgorithm;
    int sortingThreshold;
public:
    SortingSearchingAlgorithm();
    SortingSearchingAlgorithm(DynamicArray<Pair<string,string>>& keyValuePair);

    string get_sortingAlgorithm();


    void sort(D_Node<Ticket>*& ticketsHead, D_Node<Ticket>*& ticketsTail, int threshold, int condition);
    void Bubble_Sort(D_Node<Ticket>*& tickets, int size, int choice);

    void swap(D_Node<Ticket>* D_NODE01, D_Node<Ticket>* D_NODE02);
    void Selection_Sort(D_Node<Ticket>*& tickets, int size, int choice);
    void Insertion_Sort(D_Node<Ticket>*& tickets, int size, int choice);

    D_Node<Ticket>* partition(D_Node<Ticket>*& low, D_Node<Ticket>*& high, int choice);

    void quickSort(D_Node<Ticket>*& low, D_Node<Ticket>*& high, int choice);

    D_Node<Ticket>* get_midNode(D_Node<Ticket>* left,D_Node<Ticket>* right);

    void merge(D_Node<Ticket>*& left, D_Node<Ticket>* right, D_Node<Ticket>* mid, int choice);

    void mergeSort(D_Node<Ticket>*& left, D_Node<Ticket>* right, int choice);
};

#include "SortingSearchingMethods.tpp"
#endif
