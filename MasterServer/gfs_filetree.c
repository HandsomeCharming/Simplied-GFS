#include "gfs_filetree.h"
#include <string.h>


void gfs_create_node(gfs_node_t *father, file_t *file) { 
	gfs_node_t *node;

	node = (gfs_node_t*) malloc(sizeof(gfs_node_t));
	node->file = file;
	node->father = father;
	linklist_init(&node->child);
	if( father != NULL)
		linklist_push_back(father->child, (void*)node);
}


void gfs_delete_node(gfs_node_t **node) {
	gfs_node_t *father;

	while((*node)->child->size != 0){
		listnode_t *listnode = linklist_findFirst((*node)->child);
		gfs_node_t *tnode = (gfs_node_t*) listnode->elem;
		delete_Node(&tnode);
	}
	father = (*node)->father;
	linklist_delete(father->child, *node);
	free_Node(node);
	node = NULL;
}


gfs_node_t* find_node(gfs_node_t *root, file_t *file) {
	listnode_t *listnode;

	listnode = linklist_findFirst((*node)->child);

	while( listnode != NULL) {
		gfs_node_t *tnode = (gfs_node_t*)listnode->elem;
		if( file_equal(tnode->file, file) ) {
			return tnode;
		}
		listnode = listnode->next;
	}
	
	listnode = linklist_findFirst((*node)->child);
	
	while( listnode != NULL) {
		gfs_node_t *tnode = (gfs_node_t*)listnode->elem;
		gfs_node_t* result = find_node(tnode, file);
		if(result != NULL)return result;
		listnode = listnode->next;
	}
	return NULL;
}


node_t* find_node_by_name(node_t *root, char *name) {
	listnode_t *listnode;

	listnode = linklist_findFirst((*node)->child);

	while( listnode != NULL) {
		node_t *tnode = (node_t*)listnode->elem;
		if( strcmp(name, tnode->file->name) == 0 ) {
			return tnode;
		}
		listnode = listnode->next;
	}
	
	listnode = linklist_findFirst((*node)->child);
	
	while( listnode != NULL) {
		node_t *tnode = (node_t*)listnode->elem;
		node_t* result = find_node(tnode, file);
		if(result != NULL)return result;
		listnode = listnode->next;
	}
	return NULL;
}


file_t* get_file_by_path(node_t *root, const char *full_path) {
	node_t* node = NULL;
	int count,st;

	node = root;
	count = 0;
	st = 0;
	if(full_path[0] == '/') {
		count++;
		st++;
	}
	while(full_path[count] != '\0') {
		if(full_path[count] == '/') {
			char temp[33];
			strncpy(temp, full_path + st, count - st);
			node = find_node_by_name(node, temp);
			st = count + 1;
		}
		count++;
	}
	char temp[33];
	strncpy(temp, full_path + st, count - st);
	node = find_node_by_name(node, temp);

	return node->file;
}

void free_node(node_t **node) {
	file_free(&((*node)->file));
	linklist_free(&((*node)->child));
	(*node)->father = NULL;
	free(*node);
	node = NULL;
}
