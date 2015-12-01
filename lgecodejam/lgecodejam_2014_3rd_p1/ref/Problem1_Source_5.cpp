#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>

#define HASH_SIZE		100000

typedef struct tree_node_st {
	int index;
	struct tree_node_st *p_l_child;
	struct tree_node_st *p_parent;
	struct tree_node_st *p_next;
	int b_leaf;		// 0: no leaf, 1: leaf node

} tree_node_t, *p_tree_node_t;

typedef struct hash_map_node_st {
	p_tree_node_t p_tree_node;
	struct hash_map_node_st *p_next;
} hash_map_node_t, *p_hash_map_node_t;

p_tree_node_t g_root_node = NULL;
std::list<p_tree_node_t> g_list_find;
hash_map_node_t g_hash_map[HASH_SIZE] = {0};

void make_tree(int first, int second);
p_tree_node_t find_tree(int index);
p_tree_node_t find_child_node(p_tree_node_t p_start_node, int index);
int get_result(int first, int second);

void insert_hash(p_tree_node_t p_tree_node);
int get_hash_key(int index);
void clear_tree_and_hash();


int main(int argc, char **argv)
{
	FILE *fp, *w_fp;
	char line[256];
	char *pStr;
	int total_case;
	int N, M;
	int first_num, second_num;
	int i, j;
	int result;

	fp = fopen(argv[1], "rt");

	fgets(line, sizeof(line), fp);
	total_case = atoi(line);
	printf("Total Case=%d\n", total_case);

	w_fp = fopen("result.txt", "wt");
	
	for ( i = 0;  i < total_case;  i++ )
	{
		fgets(line, sizeof(line), fp);
		pStr = strtok(line, " ");
		N = atoi(pStr);
		pStr = strtok(NULL, " ");
		M = atoi(pStr);

		for ( j = 1;  j < N;  j++ )
		{
			fgets(line, sizeof(line), fp);
			pStr = strtok(line, " ");
			first_num = atoi(pStr);
			pStr = strtok(NULL, " ");
			second_num = atoi(pStr);

			// make tree
			make_tree(first_num, second_num);
		}

		for ( j = 0;  j < M;  j++ )
		{
			fgets(line, sizeof(line), fp);
			pStr = strtok(line, " ");
			first_num = atoi(pStr);
			pStr = strtok(NULL, " ");
			second_num = atoi(pStr);

			result = get_result(first_num, second_num);
			fprintf(w_fp, "%d\n", result);
		}

		fflush(w_fp);

		g_list_find.clear();
		clear_tree_and_hash();
	}

	fclose(fp);
	fclose(w_fp);

	printf("End Program!!\n");

	return 0;
}


void make_tree(int first, int second)
{
	p_tree_node_t p_node;
	p_tree_node_t p_node2;
	p_tree_node_t p_new_node;
	p_tree_node_t p_new_p_node;
	p_tree_node_t p_new_c_node;
	p_tree_node_t p_tmp_node;

	if ( g_root_node == NULL && first == 1 )		// make root node
	{
		g_root_node = new tree_node_t;

		g_root_node->p_l_child = NULL;
		g_root_node->p_next = NULL;
		g_root_node->p_parent = NULL;

		g_root_node->index = first;
		g_root_node->b_leaf = 1;

		g_list_find.push_back(g_root_node);

		insert_hash(g_root_node);
	}

	p_node = find_tree(first);
	if ( p_node == NULL ) {
		p_node = find_tree(second);
		if ( p_node == NULL ) {
			// 처음 생기는 노드 쌍
			p_new_p_node = new tree_node_t;
			
			p_new_p_node->p_l_child = NULL;
			p_new_p_node->p_next = NULL;
			p_new_p_node->p_parent = NULL;

			p_new_p_node->index = first;
			p_new_p_node->b_leaf = 0;

			p_new_c_node = new tree_node_t;
			
			p_new_c_node->p_l_child = NULL;
			p_new_c_node->p_next = NULL;
			p_new_c_node->p_parent = NULL;

			p_new_c_node->index = second;
			p_new_c_node->b_leaf = 1;

			p_new_p_node->p_l_child = p_new_c_node;
			p_new_c_node->p_parent = p_new_p_node;

			g_list_find.push_back(p_new_p_node);

			insert_hash(p_new_p_node);
			insert_hash(p_new_c_node);

			return;
		}

		// 기존에 있던 노드들 위에 부모 노드 생성
		p_new_node = new tree_node_t;
		
		p_new_node->p_l_child = NULL;
		p_new_node->p_next = NULL;
		p_new_node->p_parent = NULL;

		p_new_node->index = first;
		p_new_node->b_leaf = 0;
		p_new_node->p_l_child = p_node;
		if ( p_node->p_parent ) {
			printf("error parent exist\n");
			getchar();
		}
		p_node->p_parent = p_new_node;

		g_list_find.remove(p_node);
		g_list_find.push_back(p_new_node);

		insert_hash(p_new_node);

		return;
	}

	// p_node: 부모, p_node2: 자식
	p_node2 = find_tree(second);
	if ( p_node2 )
	{
		// 이미 모든 노드는 존재하고 연결만하면 되는 경우
		p_node2->p_parent = p_node;
		
		if ( p_node->p_l_child == NULL )
		{
			// first child node

			p_node->p_l_child = p_node2;
			p_node->b_leaf = 0;
		}

		else
		{
			for (  p_tmp_node = p_node->p_l_child;  p_tmp_node->p_next;  p_tmp_node = p_tmp_node->p_next );
			p_tmp_node->p_next = p_node2;
		}

		return;
	}

	// 부모 노드는 있고 자식 노드를 생성하는 경우
	p_new_node = new tree_node_t;
	
	p_new_node->p_l_child = NULL;
	p_new_node->p_next = NULL;
	p_new_node->p_parent = NULL;

	p_new_node->index = second;
	p_new_node->b_leaf = 1;

	insert_hash(p_new_node);

	if ( p_node->p_l_child == NULL )
	{
		// first child node

		p_new_node->p_parent = p_node;
		p_node->p_l_child = p_new_node;
		p_node->b_leaf = 0;
	}

	else
	{
		for (  p_tmp_node = p_node->p_l_child;  p_tmp_node->p_next;  p_tmp_node = p_tmp_node->p_next );
		p_new_node->p_parent = p_node;
		p_tmp_node->p_next = p_new_node;
	}
}


p_tree_node_t find_tree(int index)
{
	int key = 0;
	p_hash_map_node_t p_node;

	key = get_hash_key(index);
	for ( p_node = g_hash_map[key].p_next;  p_node;  p_node = p_node->p_next )
	{
		if ( p_node->p_tree_node->index == index )
			break;
	}

	if ( p_node == NULL )	return NULL;

	return p_node->p_tree_node;
}


p_tree_node_t find_child_node(p_tree_node_t p_start_node, int index)
{
	p_tree_node_t p_node = NULL;
	p_tree_node_t p_res_node = NULL;

	if ( p_start_node->index == index )
		return p_start_node;

	for ( p_node = p_start_node;  p_node;  p_node = p_node->p_next )
	{
		if ( p_node->index == index )
			break;

		if ( p_node->b_leaf == 0 )
		{
			p_res_node = find_child_node(p_node->p_l_child, index);
			if ( p_res_node )
				return p_res_node;
		}
	}

	return p_node;
}


int get_result(int first, int second)
{
	p_tree_node_t p_node;
	p_tree_node_t p_a_node, p_b_node;

	if ( first == second )
		return 1;

	p_a_node = find_tree(first);
	p_b_node = find_tree(second);

	if ( p_a_node->b_leaf && p_b_node->b_leaf )
		return 0;

	if ( p_a_node->b_leaf )
	{
		for ( p_node = p_a_node;  p_node;  p_node = p_node->p_parent )
		{
			if ( p_node->index == second )
				return 1;
		}
	}

	else if ( p_b_node->b_leaf )
	{
		for ( p_node = p_b_node;  p_node;  p_node = p_node->p_parent )
		{
			if ( p_node->index == first )
				return 1;
		}
	}

	else
	{
		for ( p_node = p_a_node;  p_node;  p_node = p_node->p_parent )
		{
			if ( p_node->index == second )
				return 1;
		}

		for ( p_node = p_b_node;  p_node;  p_node = p_node->p_parent )
		{
			if ( p_node->index == first )
				return 1;
		}
	}
		
	return 0;
}


void clear_tree_and_hash()
{
	p_hash_map_node_t p_node;
	p_hash_map_node_t p_target_node;
	p_tree_node_t p_tree_node;
	int i;

	for ( i = 0;  i < HASH_SIZE;  i++ )
	{
		while ( p_node = g_hash_map[i].p_next )
		{
			g_hash_map[i].p_next = p_node->p_next;
			delete p_node->p_tree_node;
			delete p_node;
		}
	}

	memset(g_hash_map, 0, sizeof(g_hash_map));
	g_root_node = NULL;
}


void insert_hash(p_tree_node_t p_tree_node)
{
	int key = 0;
	p_hash_map_node_t p_node;
	p_hash_map_node_t p_prev_node;

	key = get_hash_key(p_tree_node->index);

	p_node = new hash_map_node_t;

	p_node->p_tree_node = p_tree_node;
	p_node->p_next = g_hash_map[key].p_next;
	g_hash_map[key].p_next = p_node;
}


int get_hash_key(int index)
{
	return index % HASH_SIZE;
}
