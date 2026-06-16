#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int severity;
};

class MedicalQueue {
    Patient heap[100];
    int size = 0;

    void swapVals(Patient& a, Patient& b) { Patient temp = a; a = b; b = temp; }

    void heapifyUp(int i) {
        while (i != 0 && heap[(i - 1) / 2].severity < heap[i].severity) {
            swapVals(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i, int n, Patient arr[]) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l].severity > arr[largest].severity) largest = l;
        if (r < n && arr[r].severity > arr[largest].severity) largest = r;

        if (largest != i) {
            swapVals(arr[i], arr[largest]);
            heapifyDown(largest, n, arr);
        }
    }

public:
    void add(string n, int s) {
        if (size == 100) { cout << "Queue Full!\n"; return; }
        heap[size] = {n, s};
        heapifyUp(size);
        size++;
    }

    void treat() {
        if (size <= 0) { cout << "No Patients\n"; return; }
        if (size == 1) {
            size--;
            cout << "\nTREATING PATIENT: " << heap[0].name << " | Severity: " << heap[0].severity << endl;
            return;
        }
        Patient root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0, size, heap);

        cout << "\nTREATING PATIENT\n";
        cout << "Name: " << root.name << " | Severity: " << root.severity << endl;
    }

    void displayHeapSorted() {
        if (size == 0) { cout << "No patients in queue.\n"; return; }
        
        Patient temp[100]; 
        for (int i = 0; i < size; i++) temp[i] = heap[i];
        
        for (int i = size - 1; i > 0; i--) {
            swapVals(temp[0], temp[i]);
            heapifyDown(0, i, temp);
        }

        cout << "\nWAITING PATIENTS (Sorted by Severity):\n";
        for (int i = size - 1; i >= 0; i--) {
            cout << temp[i].name << " | Severity: " << temp[i].severity << endl;
        }
    }
};
