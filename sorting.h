
template < typename X >
X * sorting (X * array, int N, int cmp_func(X, X))
{
	int level = 1, start1, finish1, start2, 
    finish2, first, second, ppt, i;
    char res;
    first = 0;
    second = 1;
	X ** buff = new X * [2];	    
	
	for(i = 0;i < 2;i++)
        buff[i] = new X [N];
        
    for(i = 0;i < N;i += 1)
        buff[0][i] = array[i];
			
	while(level < N)
	{
		finish2 = 0;
		ppt = 0;
		
		while(1)
		{
			start1 = finish2;
			if(start1 >= N)
			    break;
			    
			finish1 = start1 + level;
			if(finish1 >= N)
			{
				i = start1;
				
				while(i < N)
				{
				    buff[second][i] = buff[first][i];
				    i += 1;
			    }
				break;
			}
			
			start2 = finish1;
			finish2 = start2 + level;
			
			if(finish2 > N)
			   finish2 = N;
			   
			while(2)
			{
				res = cmp_func(buff[first][start1], buff[first][start2]);
				if(res == -1)
				{
					buff[second][ppt] = buff[first][start1];
					start1 += 1;
					ppt += 1;
					if(start1 == finish1)
					{
						while(start2 < finish2)
						{
							buff[second][ppt] = buff[first][start2];
				         	start2 += 1;
					        ppt += 1;
						}
						break;
					}
				}else
				{
				    buff[second][ppt] = buff[first][start2];
					start2 += 1;
					ppt += 1;
					if(start2 == finish2)
					{
						while(start1 < finish1)
						{
							buff[second][ppt] = buff[first][start1];
				         	start1 += 1;
					        ppt += 1;
						}
						break;
					}	
				}
			}		
		}
		level *= 2;
		swap(first, second);
	}
	
	delete [] buff[second];
	
	return buff[first];
}

