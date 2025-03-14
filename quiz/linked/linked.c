#include "linked.h"
#include <stdio.h>
#include <stdbool.h>

bool isEmpty(address p){
	if(p == NULL) return true;
	else return false;
}

void Create_Node (address *p){
	(*p) = (address)malloc(sizeof(ElmtList));

	(*p)->next = NULL;
	(*p)->info = 0;
}

void Isi_Node (address *p, infotype nilai){
	if(isEmpty(*p)) return;
	(*p)->info = nilai;
}

void Tampil_List (address p){
	printf("\tList:");
	while(p != NULL){
		printf("%d ", p->info);
		p = p->next;
	}
	printf("\n");
}

void Ins_Awal (address *p, address *PNew){
	(*PNew)->next = (*p);
	(*p) = (*PNew);
}

void Ins_Akhir (address *p, address *PNew){
	if(isEmpty(*p)) return;
	
	address temp = (*p);

	while(!isEmpty((*p)->next)){
		(*p) = (*p)->next;
	}
	(*p)->next = (*PNew);
	
	(*p) = temp;
}
address Search (address p, infotype nilai){
	if(isEmpty(p)) return NULL;

	while(p != NULL){
		if(p->info == nilai){
			return p;
		}
		p = p->next;
	}
}

void InsertAfter (address * pBef, address * PNew){
	address temp = (*pBef)->next;
	(*pBef)->next = (*PNew);
	(*PNew)->next = temp;
}

void Del_Awal (address *p, infotype * X){
	if(isEmpty(*p)) return;
	
	address temp = (*p)->next;
	DeAlokasi(p);
	(*p) = temp;

	if(isEmpty(*p)) printf("List telah kosong");
}

void Del_Akhir (address *p, infotype * X){
	if(isEmpty(*p)) return;
	address temp = *p;
	if(isEmpty((*p)->next)){
		printf("List telah kosong");
		DeAlokasi(p);
		return;	
	}
	
	while(!isEmpty((*p)->next->next)){
		(*p) = (*p)->next;
	}
	DeAlokasi(&((*p)->next));
	*p = temp;
}

void Del_After (address * pBef, infotype * X){
	if (isEmpty(*pBef)) return;
	address temp = (*pBef)->next->next;

	DeAlokasi(&(*pBef)->next);
	(*pBef)->next = temp;
}

void Del_FirstSearch(address *p, infotype *X, infotype Target){
	if (isEmpty(*p)) return;
	if (isEmpty((*p)->next) && (*p)->info == Target){
		DeAlokasi(p);
	}
	
	address temp = *p;
	while((*p)->next != NULL){
		if((*p)->next->info == Target){
			*X = (*p)->next->info;
			break;
		}
		(*p) = (*p)->next;
	}
	
	address temp1 = (*p)->next->next;
	
	DeAlokasi(&((*p)->next));
	(*p)->next = temp1;
}

void Del_All(address *p){
	address temp;
	while(!isEmpty(*p)){
		temp = (*p)->next;
		DeAlokasi(p);
		(*p) = temp;
	}
}

void DeAlokasi (address * p){
	if(p == NULL || (*p) == NULL) return;
	
	free(*p);
	(*p) = NULL;
}


address BalikList (address * p){
	if(isEmpty(*p)) return *p;
	
	address kiri = NULL;
	address tengah = (*p);
	address kanan = NULL;

	int i = 0;
	while(!isEmpty(*p)){
		kanan = (*p)->next;
		(*p)->next = kiri;
		
		kiri = (*p);
		(*p) = kanan;
		i++;
	}	
	(*p) = kiri;
	return (*p);
}

