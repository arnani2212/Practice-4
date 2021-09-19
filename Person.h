#ifndef PERSON_H
#define PERSON_H

#define MAX_LIST 20
#define MAX_VSPACE 30

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct {
    Person data[MAX_LIST];
    int count;
} PersonStaticArrayList;

typedef struct {
    Person *data;
    int count;
    int max;
} PersonDynamicArrayList, *PersonDynamicArrayListPointer;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList;

typedef int Position;
typedef int PersonCusorBasedList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX_VSPACE];
    Position avail;
} VSpace;


Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count=0;
}
void insert_first_SAL(PersonStaticArrayList *list, Person p){
	int x;
	if(list->count<MAX_LIST){
		for(x=list->count; x>0; x--){
			list->data[x]=list->data[x-1];
		}
		list->data[x]=p;
	}
}
void insert_last_SAL(PersonStaticArrayList *list, Person p){
	if(list->count<MAX_LIST){
		list->data[list->count]=p;
		list->count++;
	}
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
	int x;
	if(list->count<MAX_LIST && (index<list->count && index >= 0)){
		for(x=list->count; x>index; x--){
			list->data[x]=list->data[x-1];
		}
		list->data[x]=p;
	}
}

void delete_first_SAL(PersonStaticArrayList *list){
	int x;
	
	if(list->count>0){
		for(x=0; x<list->count; x++){
			list->data[x]=list->data[x+1];
		}
		
		list->count--;
	}
}
void delete_last_SAL(PersonStaticArrayList *list){
	if(list->count>0){
		list->count--;
	}
}
// all ocurrences
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){
	int x,y;
	
	if(list->count>0){
		for(x=0; x<list->count; x++){
			if(list->data[x].sex='m' || list->data[x].sex='M'){
				for(y=x; y<list->count; y++){
					list->data[y]=list->data[y+1];
				}
				list->count--;
				x--;
			}
		}
	}
}

void display_SAL(PersonStaticArrayList list){
	int x;
	
	for(x=0; x<list.count; x++){
		printf("%d ",list.data[x]);
	}	
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list->data = (Person*)malloc(sizeof(Person)*MAX_LIST);
	list->count=0;
	list->max=MAX_LIST;
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int x;
	if(list->count==list->max){
		list->max*=2;
	}
	
	for(x=list->count; x>0; x--){
		list->data[x]=list->data[x-1];
	}
	
	list->data[x]=p;
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count==list->max){
		list->max*=2;
	}
	
	list->data[list->count]=p;
	list->count++;
}
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
	int x,y;
	
	if(list->count==list->max){
		list->max*=2;
	}
	
	for(x=list->count; x>index; x--){
		list->data[x]=list->data[x-1];
	}
	list->data[x]=p;
}
void delete_first_DAL(PersonDynamicArrayList *list){
	int x;
	
	if(list->count>0){
		for(x=0; x<list->count; x++){
			list->data[x]=list->data[x+1];
		}
		list->count--;
	}
}
void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count>0){
		list->count--;
	}
}
// first ocurrence
void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
	int x,y;
	
	if(list->count>0){
		for(x=0; x<list->count && strcmp(list->data[x].city,city)!=0; x++){}
		
		if(x<list->count){
			for(y=x; y<list->count;y++){
				list->data[y]=list->data[y+1];
			}
			list->count--;
		}
	}
}
void display_DAL(PersonDynamicArrayList list){
	int x;
	
	for(x=0; x<list->count ; x++){
		printf("%s ",list->data[x].name);
	}
}

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list);
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL_2(PersonDynamicArrayList *list);
void delete_last_DAL_2(PersonDynamicArrayList *list);
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name); // last ocurrence
void display_DAL_2(PersonDynamicArrayList list);

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp=(PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp!=NULL){
		temp->elem=p;
		temp->next=*list;
		*list=temp;
	}
}
void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList *trav,temp=(PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp!=NULL){
			
		for(trav=list; *trav!=NULL; trav=&(*trav)->next){}	
		temp->elem=p;
		temp->next=*trav;
		*trav=temp;
	}
}
void insert_after_LL(PersonLinkedList *list, Person p, String name){
	PersonLinkedList *trav,temp=(PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp!=NULL){
		for(trav=list; *trav!=NULL && strcmp((*trav)->elem.name,name)!=NULL; trav=&(*trav)->next){}	
		
		if(*trav!=NULL){
			temp->elem=p;
			temp->next=(*trav)->next;
			(*trav)->next=temp;
		}
	}
}
void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList temp=(PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(*list!=NULL){
		temp=*list;
		list=temp->next;
		free(temp);
	}
}
void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList *trav,temp=(PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(*list!=NULL){
		for(trav=list; *trav!=NULL;trav=&(*trav)->next);
		
		if(*trav!=NULL){
			temp=*trav;
			*trav=temp->next;
			free(temp);
		}
	}
}
// all ocurrences
void delete_by_city_LL(PersonLinkedList *list, String city){
	PersonLinkedList *trav,temp;
	
	if(*list!=NULL){
		for(trav=list; *trav!=NULL ; trav=&(*trav)->next){
			if(strcmp((*trav)->elem.city,city)==0){
				temp=*trav;
				*trav=temp->next;
				free(temp);
			}
		}
	}
}
void display_LL(PersonLinkedList list);

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
	int x;
	
	for(x=0 ; x<MAX_VSPACE; x++){
		vs->data[x].next=x-1;
	}
	
	vs->Avail=MAX_VSPACE-1;
	
	vs->avail=MAX_VSPACE-1;
	
}
Position alloc_space(VSpace *vs){
	Position avail=vs->avail;
	
	if(avail!=-1){
		vs->avail=vs->data[vs->avail].next;
	}
	return avail;
}
void free_space(VSpace *vs, Position index){
	if(index > -1 && index<MAX){
		vs->data[index].next=vs->Avail;
		vs->avail=index;
	}
}
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){

	int temp = alloc_space(vs);
	
	if(temp!=-1){
		vs->data[temp].elem=p;
		vs->data[temp].next=*list;
		*list=temp;
	}
}
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
		
	int x,temp=alloc_space(vs);
	
	if(temp!=-1){
		for(x=*list; x!=-1 && vs->data[x].next!=-1; x=vs->data[x].next){}
		
		if(vs->data[x].next==-1){
			vs->data[temp].elem=p;
			vs->data[x].next=temp;
			vs->data[temp].next=-1;
		}
	}		
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
	int x, temp=alloc_space(vs);
	
	if(temp!=-1){
		for(x=*list; x!=-1 && vs->data[x].next!=-1 && x!=index;)
	}
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
	int temp;
	
	if(*list!=-1){
		temp=*list;
		*list=vs->data[temp].next;
		free_space(vs,temp);
		
	}

}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
	int x,free;
	
	if(*list!=-1){
		for(x=*list; x!=-1 && vs->data[vs->data[x].next].next!=-1; x=vs->data[x].next){}
		
		if(vs->data[vs->data[x].next].next ==-1){
			free=vs->data[x].next;
			vs->data[x].next=-1;
			free_space(vs.free);
		}
	}
	

}
// all ocurrences
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){
	int x,free;
	
	if(*list!=-1){
//		for(x=*list; x!=-1;x=vs->data[x].next){
//			if(vs->data[vs])
//		}
	}
}
void display_CBL(VSpace vs, PersonCusorBasedList list){
	PersonCusorBasedList trav;
	
	PersonCusorBasedList x;
	for (x=list;x!=-1;x=vs.data[x].next){
		printf("[%s] ",vs.data[x].elem.name);
	}
}
#endif
