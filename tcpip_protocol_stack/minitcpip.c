main(){
    初始化libnet、libpcap；分配接收、发送缓冲区；初始化定时器；等等
	while(1)
	{
		if(发送缓冲区有数据){
			发送数据
		}
		调用select()函数等待3个文件描述符是否准备好，这三个文件描述符分别是：
		PCAP文件描述符、周知口管道读文件描述符、标准输入文件描述符
		if(PCAP文件描述符准备好){
			调用pcap_next()函数来获得下一个抓到的数据包
		}
		if(周知口读文件描述符准备好){
			读取数据
			根据进程内部的TCB中的信息，按照TCP协议规范进行分析处理
		}
		if(标准输入文件描述符准备好){
			读取数据
			分析处理，比如将内部信息回馈到标准输出文件描述符
		}
		if(超时){
			超时处理
		}
	}
}