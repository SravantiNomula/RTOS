#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	char file_buffer[10000],f1_buffer[1000],f2_buffer[1000],f3_buffer[1000],f4_buffer[1000],f5_buffer[1000];
	char buf_recv[1000],buf_send[1000];



	int sockfd, ret;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				



if(((fp1 = fopen("sensor1.txt","r"))==NULL) ||((fp2 = fopen("sensor2.txt","r"))==NULL)||((fp3 = fopen("sensor3.txt","r"))==NULL)||((fp4 = fopen("sensor4.txt","r"))==NULL)||((fp5 = fopen("sensor5.txt","r"))==NULL))
{
//sprintf(buf_send,"File could not be found!!!");
exit(0);
}



else
{
//printf("\nFile1 found!!!\n");
//sprintf(buf_send,"File found!!!\n");
//send(newSocket,buf_send,strlen(buf_send),0);
}

        	printf("Sending the file content to client....\n");
		while(!feof(fp1))//loops till eof
		{
			fgets(f1_buffer,1000,fp1);//extracts 1000 chars from file
			if (feof(fp1))
			break;
			
			
		}

		while(!feof(fp2))//loops till eof
		{
			fgets(f2_buffer,1000,fp2);//extracts 1000 chars from file
			if (feof(fp2))
			break;
			
			
		}
		while(!feof(fp3))//loops till eof
		{
			fgets(f3_buffer,1000,fp3);//extracts 1000 chars from file
			if (feof(fp3))
			break;
			
			
		}
		while(!feof(fp4))//loops till eof
		{
			fgets(f4_buffer,1000,fp4);//extracts 1000 chars from file
			if (feof(fp4))
			break;
			
			
		}
		while(!feof(fp5))//loops till eof
		{
			fgets(f5_buffer,1000,fp5);//extracts 1000 chars from file
			if (feof(fp5))
			break;
			
			
		}



		strcat(f4_buffer,f5_buffer);
		strcat(f3_buffer,f4_buffer);	
		strcat(f2_buffer,f3_buffer);
		strcat(f1_buffer,f2_buffer);
		strcpy(file_buffer,f1_buffer);


		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		fclose(fp5);



				if(strcmp(file_buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					

			

					//printf("Client: %s\n", file_buffer);
						

					
					send(newSocket,file_buffer,strlen(file_buffer),0);
					bzero(file_buffer, sizeof(file_buffer));


	
					
				}
			}
		}

	}

	close(newSocket);


	return 0;
}

