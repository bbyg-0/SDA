#include <stdio.h>
#include "linked.h"

int main(void){
	address head = NULL;
	address node = NULL;
	
	infotype temp = 0;
	address addressTemp = NULL;
	
	Create_Node(&node);
	Isi_Node(&node, 7);
	Ins_Awal(&head, &node);
	printf("1.Memasukkan node baru di awal\n");	
	Tampil_List(head);	
	
	Create_Node(&node);
	Isi_Node(&node, 11);
	Ins_Akhir(&head, &node);
	printf("2.Memasukkan node bari di akhir\n");	
	Tampil_List(head);	

	addressTemp = Search(head, 7);
	Create_Node(&node);
	Isi_Node(&node, 9);
	InsertAfter(&addressTemp, &node);	
	printf("3.Memasukkan node baru di antara 7 dan 11\n");	
	Tampil_List(head);	
	
	Create_Node(&node);
	Isi_Node(&node, 5);
	Ins_Awal(&head, &node);
	printf("4.Memasukkan node baru di awal\n");	
	Tampil_List(head);	

	Create_Node(&node);
	Isi_Node(&node, 13);
	Ins_Akhir(&head, &node);
	printf("5.Memasukkan node baru di akhir\n");	
	Tampil_List(head);	
	
	Del_Akhir(&head, &temp);
	printf("6.Menghapus elemen terakhir\n");	
	Tampil_List(head);	

	Del_FirstSearch(&head, &temp, 7);
	printf("7.Menghapus elemen yang dicari\n");	
	Tampil_List(head);	
	
	Del_Awal(&head, &temp);
	printf("8.Menghapus elemen pertama\n");	
	Tampil_List(head);	
	
	Del_All(&head);
	printf("9.Menghapus semua elemen\n");	
	Tampil_List(head);	
	
	return 0;
}
