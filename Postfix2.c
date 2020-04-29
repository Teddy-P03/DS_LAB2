int
main ()
{
	stack * st ;
	st = create_stack(100, sizeof(int)) ;
    int ud =0, inv =0;
	char tok[16] ;
	do {
		scanf("%s", tok) ;

		if (tok[0] == ';') 
			break ;

		if (isdigit(tok[0])) {
			int num = atoi(tok) ;
			push(st, &num) ;
		}
		else /* operator */ {
			switch (tok[0]) {
				case '+' : {
					int n1, n2, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n2) ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = n1 + n2 ;
					push(st, &res) ;
					break ;
				} 

				case '-' : {
					int n1, n2, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n2) ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = n1 - n2 ;
					push(st, &res) ;
					break ;
				}

				case '*' : {
					int n1, n2, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n2) ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = n1 * n2 ;
					push(st, &res) ;
					break ;
				}

				case '/' : {
					int n1, n2, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n2) ;
                    if(n2 == 0 || n1%n2 != 0){
                        ud+=1;
                        break;
                    }
                    else if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = n1 / n2 ;
					push(st, &res) ;
					break ;
				}

                case '^' : {
                    int i, n1, n2, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n2) ;
                    if(n2 < 0){
                        ud+=1;
                        break;
                    }
                    else if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = 1;
                    for(i=0;i<n2;i++){
                        res *= n1;
                    }
					push(st, &res) ;
					break ;
                }

                case '~' : {
                    int i, n1, res ;
                    if(is_empty(st)!=0){
                        inv += 1;
                        break;
                    }
					pop(st, &n1) ;
					res = (n1 * (-1));
					push(st, &res) ;
					break ;
                }

                default :   {
                    inv += 1;
                    break;
                }

			}
		}
	} while (tok[0] != ';'||inv == 0||ud == 0) ;

    
    if(inv != 0){
        printf("invalid\n") ;
    }
    else if(ud != 0){
        printf("undefined\n") ;
    }
    else{
        int result ;
        pop(st, &result) ;
        if(is_empty(st) != 0){
            printf("%d\n", result) ;
        }
        else printf("invalid\n") ; //undefined가 아닌 invalid인 이유??
    }
	
	delete_stack(st) ;
	return 0 ;
}
