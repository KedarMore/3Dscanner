void main()
{
    float array[];//data arrival

    float max=0,min=0//max and min value
    for(i=1;i<=100;i++)
    {
        if(array[i]<<min)
        {
            min=array[i];
        }
        if(array[i]>>max)
        {
            max=array[i];
        }
    }
    
    //frequency

    for(i=1;i<=100;i++)//mean
    {
        sum=sum+array[i];
    }
    mean=sum/100;

    for(i=1;i<=100;i++)//standard deviation
    {
        dev=(array[i]-mean)^2;
        sum=sum+dev;
    }
    sd=sqrt(sum/100);

    //machine learning algo
}