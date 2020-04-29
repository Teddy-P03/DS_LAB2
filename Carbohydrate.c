int
main ()
{
	char carboh[100];
	scanf("%s", carboh);
	int i=0, res=0, size = strlen(carboh);
	stack * st ;
	st = create_stack(100, sizeof(int)) ;
	while(1){
		if(carboh[i] == '('){
			int num =0;
			push(st,&num);
			i+=1;
		}
		else if(carboh[i] == 'C'){
			if(isdigit(carboh[i+1])){
				int num = atoi(&carboh[i+1]);
				int mid = 12*num;
				push(st,&mid);
				i+=2;
			}
			else{
				int mid = 12;
				push(st,&mid);
				i+=1;
			}
		}
		else if(carboh[i] == 'H'){
			if(isdigit(carboh[i+1])){
				int num = atoi(&carboh[i+1]);
				int mid = 1*num;
				push(st,&mid);
				i+=2;
			}
			else{
				int mid = 1;
				push(st,&mid);
				i+=1;
			}
		}
		else if(carboh[i] == 'O'){
			if(isdigit(carboh[i+1])){
				int num = atoi(&carboh[i+1]);
				int mid = 16*num;
				push(st,&mid);
				i+=2;
			}
			else{
				int mid = 16;
				push(st,&mid);
				i+=1;
			}
		}
		else if(carboh[i] == ')'){
			int mid =0;

			while(1){
				int isp;
				pop(st,&isp);
				if(isp != 0){
					mid += isp;

				}
				else break;
			}
			if(isdigit(carboh[i+1])){
				int num = atoi(&carboh[i+1]);
				mid = mid*num;
				push(st,&mid);
				i+=2;
			}
			else{
				push(st,&mid);
				i+=1;
			}
		}
		if(i==size) break;
	}
	while(1){
		if(is_empty(st)!=0) break;
		int mid;
		pop(st,&mid);
		res += mid;
	}
	printf("%d\n",res);
	return 0 ;
}
