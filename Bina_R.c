1.���ֲ��ұ�׼��ʽ��

int
B_search( int *base , int len , int value )
{
	if( data == NULL || len <= 0 )
	{
		return ERROR;
	}
	
	int startId , endId , midId;

	startId = 0 ;
	endId = len - 1;
	
	while( startId <= endId )
	{
		int midId = ( endId - startId ) / 2 + startId;//��ֹ����� 
		if( base[midId] == value )
		{
			return TRUE;
		}
		
		if( base[midId] > value )
		{
			endId = midId - 1;
		}
		else if( base[midId] < value )
		{
			startId = midId + 1;
		}
	}
}