#include <iostream>
#include "server.h"
#include <cstdio>

using std :: cout;
using std :: endl;

int main(void)
{
    int iData;

    CList oList1;
    oList1.Display();                               // List is Empty

    oList1.InsertAtFirst(30);
    oList1.InsertAtFirst(20);
    oList1.InsertAtFirst(10);

    oList1.Display();                               // >|10|->|20|->|30|-

    oList1.InsertAtLast(40);
    oList1.InsertAtLast(50);
    oList1.InsertAtLast(60);

    oList1.Display();                               // >|10|->|20|->|30|->|40|->|50|->|60|-

    oList1.InsertAtPosition(20, 4);              

    oList1.Display();                               // >|10|->|20|->|30|->|20|->|40|->|50|->|60|-

    iData = oList1.DeleteFirst();
    if (iData != -1)
        printf("Deleted Data is %d\n", iData);      // Deleted Data is 10

    oList1.Display();                               // >|20|->|30|->|20|->|40|->|50|->|60|-

    iData = oList1.DeleteLast();
    if (iData != -1)
        printf("Deleted Data is %d\n", iData);     // Deleted Data is 60

    oList1.Display();                               // >|20|->|30|->|20|->|40|->|50|-

    iData = oList1.DeleteAtPosition(4);
    if (iData != -1)
        printf("Deleted Data is %d\n", iData);     // Deleted Data is 40

    oList1.Display();                               // >|20|->|30|->|20|->|50|-

    iData = oList1.SearchFirstOccurance(20);
    if (iData != 0)
        printf("First %d found at %d position\n", 20, iData);   // First 20 found at 1 position

    iData = oList1.SearchLastOccurance(20);
    if (iData != 0)
        printf("Last %d found at %d position\n", 20, iData);    // Last 20 found at 3 position
    else
        cout << "Data Not found\n";

    iData = oList1.SearchAllOccurances(20);
    if (iData != 0)
        printf("%d found %d times\n", 20, iData);               // 20 found 2 times

    iData = oList1.CountNodes();
    printf("Total number of nodes = %d\n", iData);              // Toatal number of nodes = 4

    oList1.Display();                                           // >|20|->|30|->|20|->|50|-                                    

    oList1.PhysicalReverse();
    oList1.Display();                                           // >|50|->|20|->|30|->|20|-
    // oList1.PhysicalReverse();
    // oList1.Display();                                           // >|20|->|30|->|20|->|50|-

    // oList1.ReverseDisplay();                                    // >|50|->|20|->|30|->|20|-
    // oList1.Display();                                           // >|20|->|30|->|20|->|50|-

    // CList oList2;
    // oList2.InsertAtLast(100);
    // oList2.InsertAtLast(200);
    // oList2.Display();                                           // >|100|->|200|-
    // oList1.ConcatLists(oList2);
    // oList1.Display();                                           // >|20|->|30|->|20|->|50|->|100|->|200|-
    // oList2.Display();                                           // List is Empty

    // oList2.InsertAtLast(400);
    // oList2.InsertAtLast(500);
    // oList1.Display();                                           // |20|->|30|->|20|->|50|->|100|->|200|- 
    // oList2.Display();                                           // >|400|->|500|-
    // oList1.ConcatAtPosition(oList2, 7);
    // oList1.Display();                                           // >|20|->|30|->|400|->|500|->|20|->|50|->|100|->|200|-
    // oList2.Display();                                           // List is Empty

    // oList1.InsertAtLast(1000);
    // oList1.InsertAtLast(2000);
    // oList1.Display();           
    // oList2.InsertAtLast(33330);
    // oList2.InsertAtLast(22200);
    // oList2.Display();  

    // oList1.DeleteAll();
    // oList2.DeleteAll();

    // oList1.Display();                                           // List is Empty
    // oList2.Display();                                           // List is Empty

    return 0;
}