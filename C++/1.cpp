void main()
{
  int i=1,j=1;
  for(i=1;i<=90;i++)//....................SCANNED DATA
  {
    for(j=1;j<=90;j++)
    {
      a[i,j]=ascii(scanf("%d",&szBuff));
    }
  }

  int k=1;
  for(i=1;i<=90;i++)//...............................MESH
  {
    for(j=1;j<=90;j++)
    {
      l=1;
      mesh[k,l]=a[i%90,j%90];
      mesh[k,l++]=a[(i+1)%90,j%90];
      mesh[k,l++]=a[i%90,(j+1)%90];
      k++;
      l=1;
      mesh[k,l]=a[(i+1)%90,(j+1)%90];
      mesh[k++,l]=a[(i+1)%90,j%90];
      mesh[k++,l]=a[i%90,(j+1)%90];
      k++;
    }
  }

  //..................................FILE CREATION
  

}

int ascii()
{

}