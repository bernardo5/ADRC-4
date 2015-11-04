


	node*aux;
	int*distance;	//falta incialização
	int*queue;		//falta incialização
	int*seen_nodes;	//falta incialização
	int i=0;
	
	for(aux=list;aux!=NULL;aux=aux->next){
		
		if(aux->identifier==destiny) d[i]=0;
		else d[i]=-1;
		
		queue[i]=aux->identifier;
		i++;
	}
	
	while(queue[0]!=-1){
	
		for(aux=list;aux->identifier!=destiny;aux=aux->next)		
		
		aux->link
		
	}
