#include "file.h"
#include "tree.h"

int main(int argc, char *argv[]){
	
	if(argc!=2){printf("Não existe tabela de entrada\n"); exit(1);}
	char * table_txt = argv[1];
	
	
	FILE * fp;
	char * prefix = malloc(10*sizeof(char));
	int next_hop = 0;
	
	fp=fopen(table_txt, "r");
	if(fp==NULL){printf("Error: %s\n",strerror(errno)); exit(1);}
	
	node * root;
	
	while((get_table_line(fp, &prefix, &next_hop)==0)){
		/*root*/
		if(strncmp(prefix,"*",1)==0){
			root = initialize_node();
			creates_root(root, next_hop);
		}else{
			receive_node(root, prefix, next_hop);
		}
	}
	
	exit(0);
}
