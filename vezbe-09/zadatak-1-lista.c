#include <stdio.h>
#include <stdlib.h>


struct node_t{
	char data;
	struct node_t *next;
};

typedef struct node_t node;

typedef struct{
	node *head;
} list;

list* new_list();
void insert_node(list*, node*);
node* new_node(char);
void print_node(node*);
node* find_char(list*,char);
node* find_prev_char(list*,char);
void print_list(list*);
void delete_char(list*, char);
void delete_next_node(list*, node*);
void delete_head(list*);
void print_short_list(list*);
void print_menu();
void menu(list*);
int get_choice();
void run_command(list*, int);
void menu_add_char(list*);
void menu_find_char(list*);
void menu_delete_char(list*);
void menu_modify_char(list*);

int main()
{
	list *l = new_list();
	while(1) menu(l);
	return 0;
}

list* new_list()
{
	list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
	return l;
}

void insert_node(list *l, node *n)
{
	if(l->head == NULL)
		l->head = n;
	else
	{
		n->next = l->head;
		l->head = n;
	}
}

node* new_node(char data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	tmp->data = data;
	return tmp;
}

void print_node(node *n)
{
	if(n == NULL) return;
	puts("\n\n");
	printf("Node address:\t%p\n", n);
	printf("Node data:\t%c\n", n->data);
	printf("Next node:\t%p\n\n", n->next);
}

node* find_char(list *l, char c)
{
	node* tmp = find_prev_char(l, c);
	if(tmp == NULL)
		return NULL;
	if(tmp != NULL)
		return tmp->next;
	else if(l->head->data == c)
		return l->head;
	return NULL;
}

node* find_prev_char(list *l, char c)
{
	node *tmp = l->head;
	if(tmp == NULL)
		return NULL;
	else if(l->head->data == c)
		return NULL;
	while(tmp->next != NULL)
	{
		if(tmp->next->data == c)
			return tmp;
		tmp = tmp->next;
	}
	return tmp;
}

void print_list(list *l)
{
	node *tmp = l->head;
	while(tmp != NULL)
	{
		print_node(tmp);
		tmp = tmp->next;
	}
}

void delete_next_node(list *l, node *n)
{
	if(n == NULL)
		return;
	else if(n->next == NULL)
		return;
	else 
	{
		node *tmp = n->next;
		n->next = n->next->next;
		free(tmp);
	}
}

void delete_head(list *l)
{
	node *tmp = l->head;
	l->head = l->head->next;
	free(tmp);
}

		
void delete_char(list *l, char c)
{
	node *tmp = find_prev_char(l, c);
	if(tmp == NULL)
	{
		if(l->head != NULL && l->head->data == c)
			delete_head(l);
	}
	else
		delete_next_node(l, tmp);
}

void print_short_list(list *l)
{
	puts("\n\n");
	puts("The list looks like: ");
	node *tmp = l->head;
	while(tmp != NULL)
	{
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
	puts("\n");
}

void print_menu()
{
	puts("Choose a command:\n \
		1. Add char\n \
		2. Find char node\n \
		3. Delete char\n \
		4. Modify char\n \
		5. Print short list\n \
		6. Print long list\n \
		7. Exit");
}

void menu(list *l)
{
	int command = get_choice();
	run_command(l, command);
}

int get_choice()
{
	int command;
	do {
		print_menu();
		__fpurge(stdin);
		scanf("%d", &command);
	} while(command < 1 && command > 7);
	return command;
}

void run_command(list *l, int cmd)
{
	switch(cmd)
	{
		case 1: menu_add_char(l); break;
		case 2: menu_find_char(l); break;
		case 3: menu_delete_char(l); break;
		case 4: menu_modify_char(l); break;
		case 5: print_short_list(l); break;
		case 6: print_list(l); break;
		case 7: exit(0);
	}
}

void menu_add_char(list *l)
{
	char c;
	printf("Enter char to add: ");
	__fpurge(stdin);
	scanf("%c", &c);

	if(find_char(l, c) == NULL)
	{
		node *tmp = new_node(c);
		insert_node(l, tmp);
	}
}

void menu_find_char(list *l)
{
	char c;
	printf("Enter char to find: ");
	__fpurge(stdin); scanf("%c", &c);

	node *tmp = find_char(l, c);
	if(tmp == NULL) puts("There's no such char in the list.");
	else print_node(tmp);
}

void menu_delete_char(list *l)
{
	char c;
	printf("Enter char to delete: "); __fpurge(stdin); scanf("%c", &c);
	delete_char(l, c);
}

void menu_modify_char(list *l)
{
	char a, b;
	printf("Enter which char should be modified: ");
	__fpurge(stdin);
	scanf("%c", &a);

	while(1)
	{
		printf("Enter the replacement char: ");
		__fpurge(stdin);
		scanf("%c", &b);
		if(find_char(l, b)) puts("That char is already in list. Enter another.");
		else break;
	}

	node *tmp = find_char(l, a);
	if(tmp)
	{
		tmp->data = b;
	}
}
