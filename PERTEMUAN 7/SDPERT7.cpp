#include <iostream>
using namespace std;
#define MAX 5
//Deklarasi Circular Queue
class CirQueue
{
	private:
		int front;
		int rear;
		int count;
		int ele[MAX];
	public:CirQueue();
		int isFull();
		int isEmpty();
		void insertQueue(int item);
		int deleteQueue(int *item);
};

//Inisialisasi Circular Queue
CirQueue:: CirQueue()
{
	front = 0;
	rear = -1;
	count = 0;
}
//Untuk mengecek queue sudah penuh atau belum
int CirQueue:: isFull()
{
   int full=0;
   
   if( count == MAX )
   	full = 1;
   	
	return full;
}
//Untuk memeriksa antrian kosong atau tidak
int CirQueue:: isEmpty()
{
	int empty=0;
	
	if( count == 0 )
		empty = 1;
		
	return empty;
}
//Sisipkan item ke dalam antrian melingkar
void CirQueue:: insertQueue(int item)
{
  if( isFull() )
 {
 	cout<<"\nQueue Overflow";
 	return;
 }
 
 rear= (rear+1) % MAX;
 
 ele[rear] = item;
 count++;
 
 cout<<"\ndimasukkan item : "<< item;
}
//Hapus item dari circular queue
int CirQueue:: deleteQueue(int *item)
{
	if( isEmpty() )
	{
		cout<<"\nQueue Underflow";
		return -1;
 }
 *item = ele[front];
 front = (front+1) % MAX;
 count--;
 return 0;
}

int main()
{
 int item;
 CirQueue q = CirQueue();
 q.insertQueue(10);
 q.insertQueue(20);
 q.insertQueue(30);
 q.insertQueue(40);
 q.insertQueue(50);
 q.insertQueue(60);
 
 if( q.deleteQueue(&item) == 0 )
 {
 	cout<<"\nItem dihapus:"<< item<< endl;
 }
 
 if( q.deleteQueue(&item) == 0 )
 {
 	cout<<"\nItem dihapus:"<< item<< endl;
 }
 
 if( q.deleteQueue(&item) == 0 )
 {
	cout<<"\nItem dihapus:"<< item << endl;
 }
 
 if( q.deleteQueue(&item) == 0 )
 {
	cout<<"\nItem dihapus:"<< item<< endl;
 }
 
 if( q.deleteQueue(&item) == 0 )
 {
	 cout<<"\nItem dihapus:"<< item<< endl;
 }

 q.insertQueue(60);
 if( q.deleteQueue(&item) == 0 )
 {
 	cout<<"\nItem dihapus:"<< item<< endl;
 }
 
 if( q.deleteQueue(&item) == 0 )
 {

	cout<<"\nItem dihapus:"<< item<< endl;
 }
 
 cout<<"\n";
 return 0;
}

