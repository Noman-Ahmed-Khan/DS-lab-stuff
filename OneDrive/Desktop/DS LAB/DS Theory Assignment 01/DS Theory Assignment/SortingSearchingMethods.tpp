#include "SortingSearchingMethods.h" 

template <typename T1, typename T2>
Pair<T1,T2>::Pair(){}

template <typename T1, typename T2>
Pair<T1,T2>::Pair(T1 _first,T2 _second): first(_first), second(_second) {}

template <typename T1, typename T2>
void Pair<T1,T2>::set_First(T1 first){
    this->first=first;
}

template <typename T1, typename T2>
void Pair<T1,T2>::set_Second(T2 second){
    this->second=second; 
}

template <typename T1, typename T2>
T1 Pair<T1,T2>::get_First(){ 
    return first; 
}

template <typename T1, typename T2>
T2 Pair<T1,T2>::get_Second(){ 
    return second; 
}


void Config::trim(string& str){
    // Time complexity: O(n), where n is the length of the string
    str.erase(0, str.find_first_not_of(" \t")); 
    str.erase(str.find_last_not_of(" \t") + 1); 
}

void Config::load(const string& filename) {
    // Time complexity: O(n), where n is the number of lines in the file
    ifstream file(filename);
    if (!file.is_open()) throw runtime_error("Could not open the file!");
    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0]=='#') continue;
        int pos=line.find('=');
        if (pos!=string::npos) {
            string key=line.substr(0, pos);
            string value=line.substr(pos + 1);
            trim(key); trim(value);
            key_value.push_back(Pair<string,string>(key,value));
        }
    }
}

DynamicArray<Pair<string,string>> Config::get_keyValuePair(){ 
    // Time complexity: O(1)
    return key_value; 
}

SortingSearchingAlgorithm::SortingSearchingAlgorithm(){}

SortingSearchingAlgorithm::SortingSearchingAlgorithm(DynamicArray<Pair<string,string>>& keyValuePair){
    // Time complexity: O(n), where n is the number of key-value pairs
    for(int i=0 ; i<keyValuePair.size() ; i++){
        if(keyValuePair[i].get_First()=="default_sorting_algorithm") sortingAlgorithm=keyValuePair[i].get_Second();
        else if(keyValuePair[i].get_First()=="default_searching_algorithm") searchingAlgorithm=keyValuePair[i].get_Second();
        if(keyValuePair[i].get_First()=="sorting_threshold") sortingThreshold=stoi(keyValuePair[i].get_Second());
    }
};

string SortingSearchingAlgorithm::get_sortingAlgorithm(){
    // Time complexity: O(1)
    return sortingAlgorithm;
}

void SortingSearchingAlgorithm::sort(D_Node<Ticket>*& ticketsHead, D_Node<Ticket>*& ticketsTail, int threshold, int condition){
    // Time complexity: O(n log n), where n is the number of tickets, depending on the sorting algorithm used
    if(threshold<sortingThreshold && sortingAlgorithm=="Bubble_Sort") Bubble_Sort(ticketsHead,threshold,condition);
    else if(threshold<sortingThreshold && sortingAlgorithm=="Insertion_Sort") Insertion_Sort(ticketsHead,threshold,condition);
    else if(threshold<sortingThreshold && sortingAlgorithm=="Selection_Sort") Selection_Sort(ticketsHead,threshold,condition);
    else if(sortingAlgorithm=="Quick_Sort") quickSort(ticketsHead,ticketsTail,condition);
    else if(sortingAlgorithm=="Merge_Sort") mergeSort(ticketsHead,ticketsTail,condition);
}

void SortingSearchingAlgorithm::Bubble_Sort(D_Node<Ticket>*& tickets, int size, int choice) {
    // Time complexity: O(n^2), where n is the number of tickets
    for (int i=0; i<size-1; i++) {
        for (D_Node<Ticket>* curr_j=tickets->next; curr_j; curr_j=curr_j->next) {
            bool condition=false;
            if (choice==1) condition=(curr_j->prev->data.get_priority()<curr_j->data.get_priority());
            else if (choice==2) condition=(curr_j->prev->data.get_creationTime()>curr_j->data.get_creationTime());
            else condition=(curr_j->prev->data.get_customerName()>curr_j->data.get_customerName());
            if (condition) swap(curr_j->prev, curr_j);
        }
    }
}

void SortingSearchingAlgorithm::swap(D_Node<Ticket>* D_NODE01, D_Node<Ticket>* D_NODE02) {
    // Time complexity: O(1)
    Ticket tmp = D_NODE01->data;
    D_NODE01->data = D_NODE02->data;
    D_NODE02->data = tmp;
}

void SortingSearchingAlgorithm::Selection_Sort(D_Node<Ticket>*& tickets, int size, int choice) {
    // Time complexity: O(n^2), where n is the number of tickets
    for (D_Node<Ticket>* curr_i = tickets; curr_i->next; curr_i = curr_i->next) {
        D_Node<Ticket>* min = curr_i;
        for (D_Node<Ticket>* curr_j = curr_i->next; curr_j; curr_j = curr_j->next) {
            bool condition = false;
            if (choice == 1) condition = (curr_j->data.get_priority() > min->data.get_priority());
            else if (choice == 2) condition = (curr_j->data.get_creationTime() < min->data.get_creationTime());
            else condition = (curr_j->data.get_customerName() < min->data.get_customerName());
            if (condition) min = curr_j;
        }
        swap(curr_i, min);
    }
}

void SortingSearchingAlgorithm::Insertion_Sort(D_Node<Ticket>*& tickets, int size, int choice) {
    // Time complexity: O(n^2), where n is the number of tickets
    for (D_Node<Ticket>* curr_i = tickets->next; curr_i; curr_i = curr_i->next) {
        D_Node<Ticket>* key = curr_i;
        D_Node<Ticket>* curr_j = curr_i->prev;
        while (curr_j && ((choice == 1 && curr_j->data.get_priority() < key->data.get_priority()) || 
                          (choice == 2 && curr_j->data.get_creationTime() > key->data.get_creationTime()) || 
                          (choice == 3 && curr_j->data.get_customerName() > key->data.get_customerName()))) {
            curr_j->next->data = curr_j->data;
            curr_j = curr_j->prev;
        }
        if (curr_j) curr_j->next->data = key->data;
        else tickets->data = key->data;
    }
}

D_Node<Ticket>* SortingSearchingAlgorithm::partition(D_Node<Ticket>*& low, D_Node<Ticket>*& high, int choice) {
    // Time complexity: O(n), where n is the number of tickets
    D_Node<Ticket>* pivot = high;
    D_Node<Ticket>* curr_i = low;
    for (D_Node<Ticket>* curr_j = low; curr_j != high; curr_j = curr_j->next) {
        bool condition = (choice == 1) ? curr_j->data.get_priority() > pivot->data.get_priority() : 
                        (choice == 2) ? curr_j->data.get_creationTime() < pivot->data.get_creationTime() : 
                        curr_j->data.get_customerName() < pivot->data.get_customerName();
        if (condition) { swap(curr_i, curr_j); curr_i = curr_i->next; }
    }
    swap(curr_i, high);
    return curr_i;
}

void SortingSearchingAlgorithm::quickSort(D_Node<Ticket>*& low, D_Node<Ticket>*& high, int choice) {
    // Time complexity: O(n log n), where n is the number of tickets
    if (!low || low == high || low == high->next) return;
    D_Node<Ticket>* pi = partition(low, high, choice);
    quickSort(low, pi->prev, choice);
    quickSort(pi->next, high, choice);
}

D_Node<Ticket>* SortingSearchingAlgorithm::get_midNode(D_Node<Ticket>* left,D_Node<Ticket>* right){
    // Time complexity: O(n), where n is the number of tickets
    if(!left) return left;
    D_Node<Ticket>* slow=left;
    D_Node<Ticket>* fast=left;
    while(fast!=right->next && fast->next!=right->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void SortingSearchingAlgorithm::merge(D_Node<Ticket>*& left, D_Node<Ticket>* right, D_Node<Ticket>* mid, int choice) {
    // Time complexity: O(n), where n is the number of tickets
    D_Linklist<Ticket> sorted;
    D_Node<Ticket>* curr_i = left;
    D_Node<Ticket>* curr_j = mid->next;
    while (curr_i != mid->next && curr_j != right->next) {
        if ((choice == 1 && curr_i->data.get_priority() >= curr_j->data.get_priority()) || 
            (choice == 2 && curr_i->data.get_creationTime() <= curr_j->data.get_creationTime()) || 
            (choice == 3 && curr_i->data.get_customerName() <= curr_j->data.get_customerName())) {
            sorted.add_node_at_tail(curr_i->data);
            curr_i = curr_i->next;
        } else {
            sorted.add_node_at_tail(curr_j->data);
            curr_j = curr_j->next;
        }
    }
    while (curr_i != mid->next) sorted.add_node_at_tail(curr_i->data), curr_i = curr_i->next;
    while (curr_j != right->next) sorted.add_node_at_tail(curr_j->data), curr_j = curr_j->next;
    curr_i = left;
    D_Node<Ticket>* index = sorted.get_head();
    while (index && curr_i) {
        curr_i->data = index->data;
        curr_i = curr_i->next;
        index = index->next;
    }
}

void SortingSearchingAlgorithm::mergeSort(D_Node<Ticket>*& left, D_Node<Ticket>* right, int choice) {
    // Time complexity: O(n log n), where n is the number of tickets
    if (!left || left == right || left == right->next) return;
    D_Node<Ticket>* mid = get_midNode(left, right);
    mergeSort(left, mid, choice);
    mergeSort(mid->next, right, choice);
    merge(left, right, mid, choice);
}