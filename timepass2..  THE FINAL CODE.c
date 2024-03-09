#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
struct graph
{
    int weight;
    int sales;
};
int n2=0;
float pet,petrol,petrolhired;
struct graph a[100][100];
struct graph dist[100];
int vis(int d[100],int j, int k)
{
    int i;
    for(i=0;i<k;i++)
    {
        if(d[i]==j)
        {
            return 1;
        }
    }
    return 0;
}
void printmatrix(struct graph a[100][100],int n)
{
    int i,j;
    printf("\nMatrix=\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j].weight);
        }
        printf("\n");
    }
    printf("\nExpected sales in each shops=\n");
    for(i=0;i<n;i++)
    {
        printf("Shop%d->%d\t",i,a[0][i].sales);
                    printf("\n");

    }
            printf("\n");

}

void prim(int co[100][100],struct graph a[100][100],int n,int s)
{
    int i,j,co2[100],l1=0,l2=0,d[100],k=0,v,s1=s,s0=s,sh;
    float sh1;
   int sales[100],hire[100],k1=0,l11=0,l22=0;
   int sales1[100],hire1[100],d1[100],b,c1,c2;
    for(i=0;i<n;i++)
    {
        co2[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(co[i][j]==1)
            {
              co2[i]++;
            }
        }
    }
     for(i=0;i<n;i++)
    {
       // printf("%d=%d  ",i,co2[i]);

    }
    if(co2[s]>1)
    {
        printf("\n\nWe need to hire!! 2 shops connected to source ");
        printf("\n\nEnter the percent share of profit to hired man=");
        scanf("%d",&sh);
        sh1=sh*0.01;
        n2=1;
    }
    else
    {
        printf("\n\tNo need to hire!");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(co[s0][j]==1)
            {
                l1=l1+ a[s0][j].sales - a[s0][j].weight*100;
                l11=l11+a[s0][j].weight;
                sales[k]=j;
                d[k]=j;
                k++;
                s0=j;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            v=vis(d,j,k);
            if(co[s1][j]==1 && v!=1)
            {
                l2=l2+ a[s1][j].sales - a[s1][j].weight*100;
                l22=l22+a[s1][j].weight;
                hire[k1]=j;
                k1++;
                s1=j;
            }
        }
    }
    if(n2==1)
    {
        printf("\nPath1= ");
        for(i=0;i<k;i++)
        {
            printf("%d->",sales[i]);
        }
        printf("\n");
        printf("\nPath2= ");
        for(i=0;i<k1;i++)
        {
            printf("%d->",hire[i]);
        }
                printf("\n");

        printf("\nPath1 expected profit=%d\nPath2 expected profit=%d\n",l1,l2);
        printf("\nFuel required to travel through Path1=%d L\nFuel required to travel through Path2=%d L\n",l11,l22);
    }
    else
    {
      printf("\nPath1 expected profit=%d L\n",l1);
       printf("\nFuel required to travel through Path1=%d L\n",l11);
    }

    printf("\n\t SUGGESTED PATH : \n");
    if(l1>l2)
    {
        printf("\nSalesman will travel through this path to gain max profit =");
        for(i=0;i<k;i++)
        {
            printf("%d->",sales[i]);
        }
        printf("\n");
     if(n2==1)
        {
        printf("Hired person will travel through=");
        for(i=0;i<k1;i++)
        {
            printf("%d->",hire[i]);
        }
                printf("\n");
        }


        petrolhired= petrol-l11;

        if(l11<petrol)
        {
            petrol=l11;

        }
        if(petrolhired>l22)
        {
            petrolhired=l22;
            petrol=pet-petrolhired;
        }
        if(petrolhired<0)
        {
            petrolhired=0;
        }
    }

    else if(l2>=l1)
    {
        printf("\nSalesman will travel through this path to gain max profit =");
        for(i=0;i<k1;i++)
        {
            printf("%d->",hire[i]);
        }
        printf("\n");
        if(n2==1)
        {
        printf("Hired person will travel through =");
        for(i=0;i<k;i++)
        {
            printf("%d->",sales[i]);
        }
                printf("\n");
        }

        petrolhired = petrol-l22;
        if(l22<petrol)
        {
            petrol=l22;
        }
        if(petrolhired>l11)
        {
            petrolhired=l11;
            petrol=pet-petrolhired;
        }
        if(petrolhired<0)
        {
            petrolhired=0;
        }
    }


    if(n2==1)
    {
        printf("\nPETROL_salesman=%0.2f L \tPetrol_hired=%0.2f L\n",petrol,petrolhired);

    }
    else
    {
     printf("\nPetrol_salesman=%0.2f \n",petrol);
    }




c1=l1,c2=l2;
l1=0,l2=0,l11=0,l22=0;
s0=s,s1=s,k=0,k1=0;
if(c1>c2)
{
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(co[s0][j]==1)
            {
                    if(petrol>=a[s0][j].weight)
                        {
                            petrol=petrol-a[s0][j].weight;
                            b=i;
                        }
                        else
                        {
                            b=i;
                           // flag=0;
                            break;
                        }
                l1=l1+ a[s0][j].sales - a[s0][j].weight*100;
                l11=l11+a[s0][j].weight;
                sales1[k]=j;
                d1[k]=j;
                k++;
                s0=j;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            v=vis(d1,j,k);
            if(co[s1][j]==1 && v!=1)
            {
                if(petrolhired>=a[s1][j].weight)
                        {
                            petrolhired=petrolhired-a[s1][j].weight;
                            b=i;
                        }
                        else
                        {
                            b=i;
                         //   flag=0;
                            break;
                        }
                l2=l2+ a[s1][j].sales - a[s1][j].weight*100;
                l22=l22+a[s1][j].weight;
                hire1[k1]=j;
                k1++;
                s1=j;

            }
        }
    }

    printf("\nTotal profit by salesman= %0.2f",l1+l2*(1-sh1));
    if(n2==1)
    {
    printf("\nProfit by hired man=%0.2f\n",l2*sh1);
    }
}
else if(c1<=c2)
{
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(co[s0][j]==1)
            {
                    if(petrol>=a[s0][j].weight)
                        {
                            petrol=petrol-a[s0][j].weight;
                            b=i;
                        }
                        else
                        {
                            b=i;
                           // flag=0;
                            break;
                        }
                l1=l1+ a[s0][j].sales - a[s0][j].weight*100;
                l11=l11+a[s0][j].weight;
                sales1[k]=j;
                d1[k]=j;
                k++;
                s0=j;

            }
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            v=vis(d1,j,n);
            if(co[s1][j]==1 && v!=1)
            {
                if(petrolhired>=a[s1][j].weight)
                        {
                            petrolhired=petrolhired-a[s1][j].weight;
                            b=i;
                        }
                        else
                        {
                            b=i;
                           // flag=0;
                            break;
                        }
                l2=l2+ a[s1][j].sales - a[s1][j].weight*100;
                l22=l22+a[s1][j].weight;
                hire1[k1]=j;
                k1++;
                s1=j;
            }
        }
    }
    printf("\nTotal profit by salesman= %0.2f",l1*(1-sh1)+l2);
    if(n2==1)
    {
        printf("\nProfit by hired man=%0.2f\n",l1* sh1);

    }
}
if(c1>c2)
    {
        int ss=0,hi=0;;
        printf("\nSalesman visited these shops= ");
        for(i=0;i<k;i++)
        {
            printf("%d->",sales1[i]);
            if(sales1[i]>=0)
            {
                ss++;
            }

        }
        printf("\n");
        if(n2==1)
        {
        printf("Hired guy visited these shops= ");
        for(i=0;i<k1;i++)
        {
            printf("%d->",hire1[i]);
            if(hire1[i]>=0)
            {
                hi++;
            }
        }
        }
        printf("\n");
        if(ss==0)
        {
            printf("\nSalesman could not visit any shops because of low fuel ");
        }
        if(hi==0 && n2==1)
        {
            printf("\nHired guy could not visit any shops because of low fuel\n ");
        }

    }

    else if(c2>=c1)
    {
        int ss=0,hi=0;
        printf("\nSalesman visited these shops= ");
        for(i=0;i<k1;i++)
        {
            printf("%d->",hire1[i]);
            if(hire1[i]>=0)
            {
                ss++;
            }

        }
        printf("\n");
        if(n2==1)
        {
        printf("Hired guy visited these shops= ");
        for(i=0;i<k;i++)
        {
            printf("%d->",sales1[i]);
            if(sales1[i]>=0)
            {
                hi++;
            }
        }
        }
        printf("\n");
         if(ss==0)
        {
            printf("\nSalesman could not visit any shops because of low fuel ");
        }
        if(hi==0 && n2==1)
        {
            printf("\nHired guy could not visit any shops because of low fuel\n ");
        }


    }
    

}
void pri(struct graph a[100][100],int n)
{
 int dis[100],pat[100],i,j,min,u,b,s,flag=1;
 int co[100][100];
 printf("\n\nEnter source\n");
    scanf("%d",&s);

    for(i=0;i<n;i++)
    {
        dist[i].weight=a[s][i].weight;
        pat[i]=s;
    }
    dist[s].weight=0;

    for(i=0;i<n;i++)
    {
        min=999;
        for(j=0;j<n;j++)
        {
            if(dist[j].weight<min && dist[j].weight!=-1)
            {
                min=dist[j].weight;
                u=j;
            }
        }
        dist[u].weight=-1;


        for(j=0;j<n;j++)
        {
            if(a[u][j].weight!=0 && dist[j].weight!=-1 && a[u][j].weight<dist[j].weight)
            {
                dist[j].weight=a[u][j].weight;
                pat[j]=u;
            }
        }
    }


     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
      {
        co[i][j]=0;
      }
    }

    printf("edges:\n");
    for(i=0;i<n;i++)
    {
        if(pat[i]!=i)
        {
            printf("(%d,%d)\n", pat[i], i);
            co[pat[i]][i]=1;
        }
    }

    prim(co,a,n,s);
}

int main()
{
    int i,j,n,v;
    printf("Enter the number of shops\n");
    scanf("%d",&n);
  int c[n][n];//={{0,3,2,999,4},{3,0,1,999,5},{2,1,0,5,999},{999,999,5,0,2},{4,5,999,2,0}};
  int  d[n][n];//={{800,900,3000,1000,2000},{800,900,3000,1000,2000},{800,900,3000,1000,2000},{800,900,3000,1000,2000},{800,900,3000,1000,2000}};

  //int c[100][100]={{0,28,999,999,999,10,999},{28,0,16,999,999,999,14},{999,16,0,12,999,999,999},{999,999,12,0,22,999,18},{999,999,999,22,0,25,24},{10,999,999,999,25,0,999},{999,14,999,18,24,999,0}};
//int d[100][100]={{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000},{2000,6000,5000,5000,3000,4000,5000}};
     // int d[100][100]={{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000},{2000,6000,5000,5000,2000,4000,5000}};

    // int c[100][100]={{0,3,2,999,4,999},{3,0,1,999,5,999},{2,1,0,5,999,999},{999,999,5,0,2,999},{4,5,999,2,0,1},{999,999,999,999,1,0}};
   // int  d[100][100]={{800,900,3000,1000,2000,1000},{800,900,3000,1000,2000,1000},{800,900,3000,1000,2000,1000},{800,900,3000,1000,2000,1000},{800,900,3000,1000,2000,1000}};

FILE *fp =fopen("a7n.txt", "r");
    if (fp==NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            fscanf(fp, "%d ",&a[i][j].weight);
        }
    }

    for ( i=0; i<n; i++) {
        for ( j=0; j<n; j++) {
            fscanf(fp, "%d ",&a[i][j].sales);
        }
    }

    fclose(fp);
    printmatrix(a,n);
    printf("\nEnter the initial quantity of fuel\n");
    scanf("%f",&petrol);
    pet=petrol;
    printf("petrol=%0.2f L",petrol);
    pri(a,n);
}




