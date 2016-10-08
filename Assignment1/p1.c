#include<stdio.h>
#include<limits.h>
#include<string.h>
typedef struct ll{
	int wh[24];
	int bl[24];
	int s1;
	int s2;
	int s3;
	int s4;
	int barw;
	int barb;
	int pair;
	float eval;
	int flag;
}store;
typedef struct ll1{
	int wh[24];
	int bl[24];
	int barw;
	int barb;
	int pair;
	float eval;
	float evalw;
	int flag; 
}store1;
int len=0;
int chlen=0;
int dice1,dice2;
store list[1000];
store1 list1[1000];
int maxi[1000];
int len2=0;
int solve(int wh[],int bl[],int d1,int d2,int l,int m,int n,int o,int barw,int barb)
{
	int i,flag=0,j,entered=0,cnt;
	if(d1!=0 || d2!=0)
		for(i=23;i>=0;i--)
		{
			if(wh[i]>0)
			{
				cnt=0;
				if(barw>0)
					cnt=1;
				for(j=23;j>5;j--)
				{
					if(wh[j]>0)
					{
						//		printf("j : %d\n",j);
						cnt=1;
						break;
					}
				}
				//				printf("cnt :%d ",cnt);
				//				if(cnt==1)
				//				{
				if(i-d1>=0 && d1!=0)
				{
					flag=0;
					if(bl[i-d1]<=1)
					{
						entered=1;
						if(bl[i-d1]==1)
						{
							flag=1;
							bl[i-d1]=0;
						}
						wh[i]--;
						wh[i-d1]++;
						if(flag==1)
							barb++;
						if(l!=-1)
							solve(wh,bl,0,d2,l,m,i,i-d1,barw,barb);
						else
							solve(wh,bl,0,d2,i,i-d1,-1,-1,barw,barb);
						if(flag==1)
							barb--;
						wh[i-d1]--;
						wh[i]++;
						if(flag==1)
							bl[i-d1]=1;
					}
				}
				else if(cnt==0 && d1!=0)
				{
					int g=0;
					for(j=i+1;j<24;j++)
					{
						if(wh[j]>0)
						{
							g=1;
							break;
						}
					}
					//					printf("^\n");
					if(g==0)
					{
						wh[i]--;
						if(l!=-1)
							solve(wh,bl,0,d2,l,m,i,100,barw,barb);
						else
							solve(wh,bl,0,d2,i,100,-1,-1,barw,barb);
						wh[i]++;
					}
				}
				if(i-d2>=0 && d2!=0)
				{
					flag=0;
					if(bl[i-d2]<=1)
					{
						entered=1;
						if(bl[i-d2]==1)
						{
							flag=1;
							bl[i-d2]=0;
						}
						if(flag==1)
							barb++;
						wh[i]--;
						wh[i-d2]++;
						if(l!=-1)
							solve(wh,bl,d1,0,l,m,i,i-d2,barw,barb);
						else
							solve(wh,bl,d1,0,i,i-d2,-1,-1,barw,barb);
						if(flag==1)
							barb--;
						//					if(l!=-1)
						//					solve(wh,bl,d1,0);
						wh[i-d2]--;
						wh[i]++;
						if(flag==1)
						{
							bl[i-d2]=1;
						}
					}
				}
				else if(cnt==0 && d2!=0)
				{
					int g=0;
					for(j=i+1;j<24;j++)
					{
						if(wh[j]>0)
						{
							g=1;
							break;
						}
					}
					//					printf("^1\n");
					if(g==0)
					{
						wh[i]--;
						if(l!=-1)
							solve(wh,bl,d1,0,l,m,i,100,barw,barb);
						else
							solve(wh,bl,d1,0,i,100,-1,-1,barw,barb);
						wh[i]++;
					}
				}
				//				}
				//				else
				//				{
				//					if(i-d1>=0)
				//					{
				//					}
				//				}
			}
		}
	if((d1==0 && d2==0) || (d1==0) ||(d2==0))
	{
		int cnta=0,cntb=0;
		for(i=0;i<24;i++)
		{
			list[len].wh[i]=wh[i];
			list[len].bl[i]=bl[i];
			if(wh[i]>0)
				cnta+=wh[i];
			if(bl[i]>0)
				cntb+=bl[i];
			list[len].s1=l;
			list[len].s2=m;
			list[len].s3=n;
			list[len].s4=o;
			if(d1==0 && d2==0)
				list[len].flag=1;
			else if(d2==0)
				list[len].flag=3;
			else if(d1==0) 
				list[len].flag=2;
		}
		if(d1==0 && d2==0)
			chlen++;

		//		for(i=0;i<24;i++)
		//			//printf("%d ",bl[i]);
		//		//printf("\n");
		//		for(i=0;i<24;i++)
		//			//printf("%d ",wh[i]);
		//		//printf("\n");
		//		//printf("cnt :  %d %d\n",cnta,cntb);
		//	list[len].barw=15-cnta;
		//	list[len].barb=15-cntb;
		list[len].barw=barw;
		list[len].barb=barb;
		//		if(barw!=15-cnta || barb!=15-cntb)
		//			printf("NOT\n");
		int pip=0,wblot=0,bblot=0,good_pos=0,altpos=0,pairs=0,hold=0,anc_home=0,cont_anc_opp=0,max=0,cont_anc_home=0,cont_anc=0,opp_anc_home=0,opp_anc_opp=0,opp_anc=0,anc_opp=0;
		for(i=5;i<24;i++)
		{
			pip+=wh[i]*(i-5);
		}
		for(i=6;i<24;i++)
		{
			hold+=wh[i]*(i-6);
		}
		for(i=0;i<24;i++)
		{
			if(wh[i]==1)
				wblot++;
			if(bl[i]==1)
				bblot++;
		}
		if(wh[19]>=2)
			good_pos++;
		if(wh[17]>=2)
			good_pos++;
		for(i=17;i<24;i++)
		{
			if(wh[i]>=2)
				altpos++;
		}
		for(i=0;i<=5;i++)
		{
			if(wh[i]>=2)
				anc_home++;
		}
		max=0;
		for(i=18;i<24;i++)
		{
			if(wh[i]>0)
				max++;
			if(wh[i]<=0)
				max=0;
			if(cont_anc_opp<max)
				cont_anc_opp=max;
		}
		max=0;
		for(i=0;i<6;i++)
		{
			if(wh[i]>0)
				max++;
			if(wh[i]<=0)
				max=0;
			if(cont_anc_home<max)
				cont_anc_home=max;
		}
		max=0;
		for(i=6;i<18;i++)
		{
			if(wh[i]>0)
				max++;
			if(wh[i]<=0)
				max=0;
			if(cont_anc<max)
				cont_anc=max;
		}
		for(i=0;i<=5;i++)
		{
			if(bl[i]>=2)
				anc_opp++;
		}
		max=0;
		for(i=18;i<24;i++)
		{
			if(bl[i]>0)
				max++;
			if(bl[i]<=0)
				max=0;
			if(opp_anc_opp<max)
				opp_anc_opp=max;
		}
		max=0;
		for(i=0;i<6;i++)
		{
			if(bl[i]>0)
				max++;
			if(bl[i]<=0)
				max=0;
			if(opp_anc_home<max)
				opp_anc_home=max;
		}
		max=0;
		for(i=6;i<18;i++)
		{
			if(bl[i]>0)
				max++;
			if(bl[i]<=0)
				max=0;
			if(opp_anc<max)
				opp_anc=max;
		}
		//bar's point



		for(i=0;i<17;i++)
		{
			if(wh[i]>=2)
				pairs++;
		}
		list[len].pair=pairs;
		//list[len++].eval=-4*wblot +2*(bblot+pairs)+6*good_pos+4*(altpos-good_pos)-0.9*(hold);
		list[len++].eval=-4*wblot +2*(bblot+pairs)+6*good_pos+4*(altpos-good_pos)-0.9*(hold)+3*(anc_home-anc_opp)+7*(cont_anc_opp-opp_anc_opp)+5*(cont_anc_home-opp_anc_home)+4*(cont_anc-opp_anc);
		//		printf("%f\n",list[len-1].eval);
		//		//printf("eval: %f  wblot: %d bblot: %d pairs: %d good_pos: %d altpos: %d hold: %d\n",list[len-1].eval,wblot,bblot,pairs,good_pos,altpos,hold);
	}
}
float evaluate(int wh[],int bl[],int barw,int barb)
{
	int i;
	int pip=0,wblot=0,bblot=0,good_pos=0,altpos=0,pairs=0,hold=0,anc_home=0,cont_anc_opp=0,max=0,cont_anc_home=0,cont_anc=0,opp_anc_home=0,opp_anc_opp=0,opp_anc=0,anc_opp=0,anc_wh=0,anc_bl=0;
	int fl=0,ind=-1,ni=0,mi=0;
	for(i=23;i>=0;i--)
	{
		if(wh[i]>0)
		{
			ind=i;
			break;
		}
	}
	for(i=0;i<24;i++)
	{
		if(wh[i]>1)
			anc_wh++;
		if(bl[i]>1)
			anc_bl++;
	}
	if(ind>0)
	{
		for(i=ind;i>=0;i--)
		{
			if(bl[i]>0)
			{
				fl=1;
				break;
			}
		}
	}
	for(i=0;i<24;i++)
	{
		if(i<6 && wh[i]>0)
			ni+=1;
		else if(i>=6)
		{
			if(wh[i]>0 && wh[i]<5)
			{
				ni+=2;
			}
			else if(wh[i]>0)
				ni-=1;
		}
		if(bl[i]>0 && bl[i]<5)
			mi-=2;
		else if(bl[i]>0)
			mi+=1;
	}
	for(i=0;i<24;i++)
	{
		pip+=wh[i]*(i);
	}
	int bpip=0;
	for(i=23;i>=0;i--)
		bpip+=bl[i]*(23-i);
	for(i=6;i<24;i++)
	{
		hold+=wh[i]*(i-6);
	}
	for(i=0;i<24;i++)
	{
		if(wh[i]==1)
			wblot++;
		if(bl[i]==1)
			bblot++;
	}
	if(wh[19]>=2)
		good_pos++;
	if(wh[17]>=2)
		good_pos++;
	for(i=17;i<24;i++)
	{
		if(wh[i]>=2)
			altpos++;
	}
	for(i=0;i<=5;i++)
	{
		if(wh[i]>=2)
			anc_home++;
	}
	max=0;
	for(i=18;i<24;i++)
	{
		if(wh[i]>0)
			max++;
		if(wh[i]<=0)
			max=0;
		if(cont_anc_opp<max)
			cont_anc_opp=max;
	}
	max=0;
	for(i=0;i<6;i++)
	{
		if(wh[i]>0)
			max++;
		if(wh[i]<=0)
			max=0;
		if(cont_anc_home<max)
			cont_anc_home=max;
	}
	max=0;
	for(i=6;i<18;i++)
	{
		if(wh[i]>0)
			max++;
		if(wh[i]<=0)
			max=0;
		if(cont_anc<max)
			cont_anc=max;
	}
	for(i=0;i<=5;i++)
	{
		if(bl[i]>=2)
			anc_opp++;
	}
	max=0;
	for(i=18;i<24;i++)
	{
		if(bl[i]>0)
			max++;
		if(bl[i]<=0)
			max=0;
		if(opp_anc_opp<max)
			opp_anc_opp=max;
	}
	max=0;
	for(i=0;i<6;i++)
	{
		if(bl[i]>0)
			max++;
		if(bl[i]<=0)
			max=0;
		if(opp_anc_home<max)
			opp_anc_home=max;
	}
	max=0;
	for(i=6;i<18;i++)
	{
		if(bl[i]>0)
			max++;
		if(bl[i]<=0)
			max=0;
		if(opp_anc<max)
			opp_anc=max;
	}
	//bar's point



	for(i=0;i<17;i++)
	{
		if(wh[i]>=2)
			pairs++;
	}
	float ans;
	if(fl==1)
	{
		//ans=0.1*(ni+mi)+0.025*(barb-barw)+0.37025*(bblot-wblot)+0.025*(anc_wh-anc_bl)+0.0025*(bpip-pip);
		ans=0.1*(ni+mi)+0.025*(barb-barw)+0.37025*(bblot-wblot)+0.025*(anc_wh-anc_bl)+0.0025*(bpip-pip)+0.0925625*(pairs)+0.2776875*(good_pos)+0.185125*(altpos-good_pos)+0.13884375*(anc_home-anc_opp)+0.32396875*(cont_anc_opp-opp_anc_opp)+0.23140625*(cont_anc_home-opp_anc_home)+0.185125*(cont_anc-opp_anc);
		return ans;
	}
	else
	{
		ans=0.025*(bpip-pip);
		return ans;
	}
	//list[len].pair=pairs;
	//	ans=-4*wblot +2*(bblot+pairs)+6*good_pos+4*(altpos-good_pos)-0.9*(hold);
	ans=-8*wblot +2*(bblot+pairs)+6*good_pos+4*(altpos-good_pos)-0.9*(hold)+3*(anc_home-anc_opp)+7*(cont_anc_opp-opp_anc_opp)+5*(cont_anc_home-opp_anc_home)+4*(cont_anc-opp_anc);
	//		printf("%f\n",list[len-1].eval);
	return ans;
}

int solve2(int wh[],int bl[],int d1,int d2,int dice1,int dice2,int barw,int barb)
{
	int i,flag=0,j,entered=0;
	if(d1!=0 || d2!=0)
		for(i=23;i>=0;i--)
		{
			if(wh[i]>0)
			{
				if(i-d1>=0 && d1!=0)
				{
					flag=0;
					if(bl[i-d1]<=1)
					{
						entered=1;
						if(bl[i-d1]==1)
						{
							flag=1;
							bl[i-d1]=0;
						}
						if(flag==1)
							barb++;
						wh[i]--;
						wh[i-d1]++;
						solve2(wh,bl,0,d2,dice1,dice2,barw,barb);
						wh[i-d1]--;
						wh[i]++;
						if(flag==1)
							barb--;
						if(flag==1)
							bl[i-d1]=1;
					}
				}
				if(i-d2>=0 && d2!=0)
				{
					flag=0;
					if(bl[i-d2]<=1)
					{
						entered=1;
						if(bl[i-d2]==1)
						{
							flag=1;
							bl[i-d2]=0;
						}
						if(flag==1)
							barb++;
						wh[i]--;
						wh[i-d2]++;
						solve2(wh,bl,d1,0,dice1,dice2,barw,barb);
						//					if(l!=-1)
						//					solve(wh,bl,d1,0);
						wh[i-d2]--;
						wh[i]++;
						if(flag==1)
							barb--;
						if(flag==1)
						{
							bl[i-d2]=1;
						}
					}
				}
			}
		}
	if((d1==0 && d2==0) || (d1==0) ||(d2==0))
	{
		int cntb=0,cntw=0;
		for(i=0;i<24;i++)
		{
			list1[len2].wh[i]=wh[i];
			list1[len2].bl[i]=bl[i];
			if(wh[i]>0)
				cntb+=wh[i];
			if(bl[i]>0)
				cntw+=bl[i];
			//			list1[len2].s1=0;
			//			list1[len2].s2=0;
			//			list1[len2].s3=0;
			//			list1[len2].s4=0;
			if(d1==0 && d2==0)
				list1[len2].flag=1;
			else if(d2==0)
				list1[len2].flag=3;
			else if(d1==0)
				list1[len2].flag=2;
		}
		//		list1[len2].barw=15-cntw;
		//		list1[len2].barb=15-cntb;
		list1[len2].barw=barw;
		list1[len2].barb=barb;
		int pip=0,wblot=0,bblot=0,good_pos=0,altpos=0,pairs=0,hold=0;
		int wpip=0,wgood_pos=0,waltpos=0,wpairs=0,whold=0;
		for(i=5;i<24;i++)
		{
			pip+=bl[i]*(i-5);
			wpip+=wh[i]*(i-5);
		}
		for(i=6;i<24;i++)
		{
			hold+=bl[i]*(i-6);
			whold+=wh[i]*(i-6);
		}
		for(i=0;i<24;i++)
		{
			if(bl[i]==1)
				bblot++;
			if(wh[i]==1)
				wblot++;
		}
		if(bl[19]>=2)
			good_pos++;
		if(wh[19]>=2)
			wgood_pos++;
		if(bl[17]>=2)
			good_pos++;
		if(wh[19]>=2)
			wgood_pos++;
		for(i=17;i<24;i++)
		{
			if(bl[i]>=2)
				altpos++;
			if(wh[i]>=2)
				waltpos++;
		}
		for(i=0;i<17;i++)
		{
			if(bl[i]>=2)
				pairs++;
			if(wh[i]>=2)
				wpairs++;
		}
		list1[len2].pair=pairs;
		list1[len2].eval=evaluate(wh,bl,barw,barb);
		int temp[24],temp1[24],ch=0;
		for(i=23;i>=0;i--)
			temp[ch++]=wh[i];
		ch=0;
		for(i=23;i>=0;i--)
			temp1[ch++]=bl[i];
		list1[len2++].evalw=evaluate(temp1,temp,barb,barw);
		//		list1[len2].evalw=-4*bblot +2*(wblot+pairs)+6*good_pos+4*(altpos-good_pos)-0.9*(hold);
		//		list1[len2++].eval=-4*wblot +2*(bblot+wpairs)+6*wgood_pos+4*(waltpos-wgood_pos)-0.9*(whold);
	}
}
int checking(int wh[],int bl[],int d1,int d2,int dice1,int dice2,int barw,int barb)
{
	int flag;
	if(barw==0)
	{
		//		//printf("ENT\n");
		//	if(s=="Bob")
		//		solve(bl,wh,d1,d2);
		//	else
		//		solve2(wh,list[i].wh,h,k,h,k);
		solve2(wh,bl,d1,d2,dice1,dice2,barw,barb);
	}
	else if(barw==1)
	{
		//		if(c<0)
		//			c=1;
		flag=0;
		if(bl[24-d1]<2 && 24-d1>=0)
		{
			if(bl[24-d1]==1)
			{
				flag=1;
				bl[24-d1]=0;
				barb++;
			}
			barw--;
			wh[24-d1]++;
			solve2(wh,bl,0,d2,dice1,dice2,barw,barb);
			wh[24-d1]--;
			barw++;
			if(flag==1)
			{
				bl[24-d1]=1;
				barb--;
			}
		}
		flag=0;
		if(bl[24-d2]<2 && 24-d2>=0)
		{
			if(bl[24-d2]==1)
			{
				flag=1;
				bl[24-d2]=0;
				barb++;
			}
			barw--;
			wh[24-d2]++;
			solve2(wh,bl,d1,0,dice1,dice2,barw,barb);
			wh[24-d2]--;
			barw++;
			if(flag==1)
			{
				bl[24-d2]=1;
				barb--;
			}
		}
	}
	else if(barw==2)
	{
		int check=0,check1=0;
		//		if(c<0)
		//			c=2;
		check=0;
		check1=0;
		if(bl[24-d1]<2 && 24-d1>=0)
		{
			if(bl[24-d1]==1)
			{
				flag=1;
				bl[24-d1]=0;
				barb++;
			}
			barw--;
			wh[24-d1]++;
			check=1;
		}
		if(bl[24-d2]<2 && 24-d2>=0)
		{
			check1=1;
			if(bl[24-d2]==1)
			{
				flag=1;
				bl[24-d2]=0;
				barb++;
			}
			barw--;
			wh[24-d2]++;
		}
		if(check==1 && check1==1)
			solve2(wh,bl,0,0,dice1,dice2,barw,barb);
		if(check==1 && check1==0)
			solve2(wh,bl,0,0,dice1,dice2,barw,barb);
		if(check==0 && check1==1)
			solve2(wh,bl,0,0,dice1,dice2,barw,barb);
		if(check==0 && check1==0)
			solve2(wh,bl,0,0,dice1,dice2,barw,barb);
	}
}
int main()
{
	int a[24],b[12],c,d1,d2,i,wh[24]={0},bl[24]={0},j,flag,barw=0,barb=0;
	char s[100],ch,ch1;
	//	scanf("%s",s);
	for(i=0;i<24;i++)
		scanf("%d",&a[i]);
	ch=getchar();
	//ch1=getchar();
	//printf("ch:  %c",ch);
	//if(ch1!='\n')
	scanf("%[^\n]s",s);
//	printf("s : %s\n",s);
	//	//printf("%s\n",s);
	//	for(i=0;i<12;i++)
	//		scanf("%d",&b[i]);
	scanf("%d%d",&d1,&d2);
	dice1=d1;
	dice2=d2;
	//if(ch1=='a')
	//	barw++;
//	if(ch1=='b')
//		barb++;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='a')
			barw++;
		if(s[i]=='b')
			barb++;
	}
	/*	for(i=0;i<24;i++)
		{
	//	scanf
	if(a[i]>0)
	wh[24-i-1]=a[i];
	else
	bl[24-i-1]=-a[i];
	}
	 */
	for(i=0;i<12;i++)
	{
		if(a[i]>0)
			wh[23-i]=a[i];
		if(a[i+12]>0)
			wh[23-i-12]=a[i+12];
	}
	for(i=0;i<12;i++)
	{
		if(a[i]<0)
			bl[23-i]=-a[i];
		if(a[i+12]<0)
			bl[23-i-12]=-a[i+12];
	}
	//printf("%d %d\n",barw,barb);
	//for(i=0;i<24;i++)
	//printf("%d ",wh[i]);
	//printf("\n");
	/*	if((strcmp(s,"Bob"))==0)
		{
	//		//printf("ENTERED\n");
	for(i=0;i<12;i++)
	{
	wh[i]=wh[24-i-1]+wh[i];
	wh[24-i-1]=wh[i]-wh[24-i-1];
	wh[i]=wh[i]-wh[24-i-1];
	bl[i]=bl[24-i-1]+bl[i];
	bl[24-i-1]=bl[i]-bl[24-i-1];
	bl[i]=bl[i]-bl[24-i-1];
	}
	//		//printf("STOP\n");
	for(i=0;i<24;i++)
	{
	wh[i]=wh[i]+bl[i];
	bl[i]=wh[i]-bl[i];
	wh[i]=wh[i]-bl[i];
	}

	}
	 */
	//	for()
	//	//printf("START\n");
	//	for(i=0;i<12;i++)
	//		//printf("%d ",wh[i]);
	//	//printf("\n");
	//	for(i=12;i<24;i++)
	//		//printf("%d ",wh[i]);
	//	//printf("\n");
	//	//printf("END\n");
	if(barw==0)
	{
		//	if(s=="Bob")
		//		solve(bl,wh,d1,d2);
		//	else
		solve(wh,bl,d1,d2,-1,-1,-1,-1,barw,barb);
	}
	else if(barw==1)
	{
		if(c<0)
			c=1;
		flag=0;
		if(bl[24-d1]<2)
		{
			if(bl[24-d1]==1)
			{
				flag=1;
				bl[24-d1]=0;
				barb++;
			}
			barw--;
			wh[24-d1]++;
			solve(wh,bl,0,d2,25,24-d1,-1,-1,barw,barb);
			wh[24-d1]--;
			barw++;
			if(flag==1)
			{
				barb--;
				bl[24-d1]=1;
			}
		}
		flag=0;
		if(bl[24-d2]<2)
		{
			if(bl[24-d2]==1)
			{
				flag=1;
				bl[24-d2]=0;
				barb++;
			}
			barw--;
			wh[24-d2]++;
			solve(wh,bl,d1,0,25,24-d2,-1,-1,barw,barb);
			wh[24-d2]--;
			barw++;
			if(flag==1)
			{
				bl[24-d2]=1;
				barb--;
			}
		}
	}
	else if(barw==2)
	{
		int check=0,check1=0;
		if(c<0)
			c=2;
		check=0;
		check1=0;
		if(bl[24-d1]<2)
		{
			if(bl[24-d1]==1)
			{
				flag=1;
				bl[24-d1]=0;
				barb++;
			}
			barw--;
			wh[24-d1]++;
			check=1;
		}
		if(bl[24-d2]<2)
		{
			check1=1;
			if(bl[24-d2]==1)
			{
				flag=1;
				bl[24-d2]=0;
				barb++;
			}
			barw--;
			wh[24-d2]++;
		}
		if(check==1 && check1==1)
			solve(wh,bl,0,0,25,24-d1,25,24-d2,barw,barb);
		if(check==1 && check1==0)
			solve(wh,bl,0,0,25,24-d1,-1,-1,barw,barb);
		if(check==0 && check1==1)
			solve(wh,bl,0,0,25,24-d2,-1,-1,barw,barb);
		if(check==0 && check1==0)
			solve(wh,bl,0,0,-1,-1,-1,-1,barw,barb);
	}
	int check=0;
	int check1=0;
	for(i=0;i<len;i++)
	{
		if(list[i].flag==1)
		{
			check=1;
			break;
		}
	}
	//printf("ENTERD1 %d %d %d\n",check,len,chlen);
	if(check==0)
	{
		if(dice1>=dice2)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].flag==2)
				{
					check=2;
					break;
				}
			}
		}
	}
	if(check==0)
	{
		if(dice2>=dice1)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].flag==3)
				{
					check=3;
					break;
				}
			}
		}
	}
	/*	//printf("%d\n",len);
		for(i=0;i<len;i++)
		{
	//printf("\n#############################################\n");
	if(list[i].flag==check)
	{
	for(j=0;j<12;j++)
	{
	//printf("%d ",list[i].wh[j]);
	}
	//printf("\n");
	for(j=12;j<24;j++)
	{
	//printf("%d ",list[i].wh[j]);
	}
	//printf("\n");
	//printf("%f\n",list[i].eval);
	//printf("%d -> %d\n",list[i].s1,list[i].s2);
	//printf("%d -> %d\n",list[i].s3,list[i].s4);
	//printf("\n#############################################\n");
	}
	}*/
	//		//printf("%d\n",len);
	int h,k,m,ind=0,y;
	int temp_num=0,tempind;
	float val,max1=-INT_MAX,max2=-INT_MAX;
	//printf("ENTERD %d %d\n",check,len);
	//	for(i=0;i<len;i++)
	//	{
	//		//printf("%f\n",list[i].eval);
	//	}
	int temp[24],temp1[24],kl;
	for(i=0;i<len;i++)
	{
		if(list[i].flag==check)
		{
			val=0;
			for(h=1;h<=6;h++)
			{
				for(k=h;k<=6;k++)
				{
					tempind=0;
					max2=INT_MAX;
					for(kl=23;kl>=0;kl--)
					{
						temp[23-kl]=list[i].bl[kl];
						temp1[23-kl]=list[i].wh[kl];
					}
					//				//printf("%d\n",list[i].barb);
					checking(temp,temp1,h,k,h,k,list[i].barb,list[i].barw);
					for(y=0;y<len2;y++)
					{
						if(list1[y].flag==1)
						{
							check1=1;
							break;
						}
					}
					if(check1==0)
					{
						if(h>=k)
						{
							for(y=0;y<len2;y++)
							{
								if(list1[y].flag==2)
								{
									check1=2;
									break;
								}
							}
						}
					}
					if(check1==0)
					{
						if(k>=h)
						{
							for(y=0;y<len2;y++)
							{
								if(list1[y].flag==3)
								{
									check1=3;
									break;
								}
							}
						}
					}
					for(m=0;m<len2;m++)
					{
						if(list1[m].flag==check1)
						{
							if(list1[m].evalw<max2)
							{
								max2=list1[m].evalw;
								tempind=m;
							}
						}
						//printf("%f\n",list1[m].evalw);

						//					for(j=0;j<24;j++)
						//						printf("%d ",list1[m].wh[j]);
						//					printf("\n");
					}

					//					max2=list1[tempind].evalw;
					if(h!=k)
						val+=((max2*1.0)/18);
					else
						val+=((max2*1.0)/36);
					temp_num+=len2;
					//		printf("####### %f #########\n",max2);
					//					printf("%d\n",len2);
					len2=0;
					//				//printf("FINISHED %d %d\n",h,k);
				}
			}
			//			printf("val::  %f\n",val);
			if(val>max1)
			{
				max1=val;
				ind=i;
			}
			//			for(j=0;j<24;j++)
			//				printf("%d ",list[i].bl[j]);
			//			printf("\n");
			//			//printf("####################\n");
			//printf("temp %d\n",temp_num);
		}
	}
	//	for(i=0;i<24;i++)
	//printf("%d ",list[ind].wh[i]);
	//printf("\n");
	//	for()
	//	{
	//	}
	//	//printf("LEFT %d\n",temp_num);
	int max=-INT_MAX;
	k=0;
	for(i=0;i<len;i++)
	{
		if(list[i].eval>max && list[i].flag==check)
		{
			max=list[i].eval;
			k=i;
		}
	}
	k=ind;
	int placed=0;
	//	printf("%d %d %d %d\n",list[k].s1,list[k].s2,list[k].s3,list[k].s4);
	if(len==0)
	{
		printf("pass\n");
		printf("pass\n");
	}
	else
	{
		if(list[k].s1<24 && list[k].s2>=0 && list[k].s1>=0)
			printf("%d ",24-list[k].s1);
		if(list[k].s1==25 && list[k].s2>=0)
			printf("Z ");
		if(list[k].s2==100)
			printf("O\n");

		if(list[k].s2==25)
			printf("Z\n");
		if(list[k].s2<24 && list[k].s2>=0)
			printf("%d\n",24-list[k].s2);
		if(list[k].s2<0)
			placed++;
		if(list[k].s3<24 && list[k].s4>=0 && list[k].s3>=0)
			printf("%d ",24-list[k].s3);
		if(list[k].s3==25 && list[k].s4>=0)
			printf("Z ");

		if(list[k].s4==25)
			printf("Z\n");
		if(list[k].s4==100)
			printf("O\n");
		if(list[k].s4<24 && list[k].s4>=0)
			printf("%d\n",24-list[k].s4);
		if(list[k].s4<0)
			placed++;
		for(i=0;i<placed;i++)
			printf("pass\n");
		/*	if((strcmp(s,"Bob"))!=0)
			{
			if(list[k].s1>=12 && list[k].s1<24 && list[k].s2>=0)
			{
			printf("B%d ",list[k].s1-11);
			}
			if(list[k].s1==25 && list[k].s2>=0)
			printf("Z ");
			if(list[k].s1<12 && list[k].s1>=0 && list[k].s2>=0)
			{
			printf("A%d ",12-list[k].s1);
			}
			if(list[k].s2==25)
			printf("Z\n");
			if(list[k].s2>=12 && list[k].s2<24)
			{
			printf("B%d\n",list[k].s2-11);
			}
			if(list[k].s2<12 && list[k].s2>=0)
			{
			printf("A%d\n",12-list[k].s2);
			}
			if(list[k].s2<0)
			{
			placed++;
		//			printf("pass\n");
		}
		if(list[k].s3>=12 && list[k].s3<24 && list[k].s4>=0)
		{
		printf("B%d ",list[k].s3-11);
		}
		if(list[k].s3==25 && list[k].s4>=0)
		printf("Z ");
		if(list[k].s3<12 && list[k].s3>=0 && list[k].s4>=0)
		{
		printf("A%d ",12-list[k].s3);
		}
		if(list[k].s4>=12 && list[k].s4<24)
		{
		printf("B%d\n",list[k].s4-11);
		}
		if(list[k].s4==25)
		printf("Z\n");
		if(list[k].s4<12 && list[k].s4>=0)
		{
		printf("A%d\n",12-list[k].s4);
		}
		if(list[k].s4<0)
		{
		placed++;
		//			printf("pass\n");
		}
		for(i=0;i<placed;i++)
		printf("pass\n");
		}
		else
		{
		if(list[k].s1>=12 && list[k].s1<24 && list[k].s2>=0)
		{
		printf("A%d ",list[k].s1-11);
		}
		if(list[k].s1==25 && list[k].s2>=0)
		printf("Z ");
		if(list[k].s1<12 && list[k].s1>=0 && list[k].s2>=0)
		{
		printf("B%d ",12-list[k].s1);
		}
		if(list[k].s2==25)
		printf("Z\n");
		if(list[k].s2>=12 && list[k].s2<24)
		{
		printf("A%d\n",list[k].s2-11);
	}
	if(list[k].s2<12 && list[k].s2>=0)
	{
		printf("B%d\n",12-list[k].s2);
	}
	if(list[k].s2<0)
	{
		placed++;
		//	printf("pass\n");
	}
	if(list[k].s3>=12 && list[k].s3<24 && list[k].s4>=0)
	{
		printf("A%d ",list[k].s3-11);
	}
	if(list[k].s3==25 && list[k].s4>=0)
		printf("Z ");
	if(list[k].s3<12 && list[k].s3>=0 && list[k].s4>=0)
	{
		printf("B%d ",12-list[k].s3);
	}
	if(list[k].s4>=12 && list[k].s4<24)
	{
		printf("A%d\n",list[k].s4-11);
	}
	if(list[k].s4==25)
		printf("Z\n");
	if(list[k].s4<12 && list[k].s4>=0)
	{
		printf("B%d\n",12-list[k].s4);
	}
	if(list[k].s4<0)
	{
		placed++;
		//	printf("pass\n");
	}
	for(i=0;i<placed;i++)
		printf("pass\n");

	}*/
	}
	return 0;
}
