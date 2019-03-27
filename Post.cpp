#include "Post.h"

Post::Post()
{
}

Post::Post(Question q){
	question = q;
}
/*
void Post::add(){
	ofstream post("Forum.bin", ios::binary | ios::app);
	if (post.is_open()){
		post.write((char *)(this), sizeof(Post));
		post.close();
	}
}

void Post::delet(){

}

void Post::update(){

}

void Post::search_user(){

}

void Post::see(){
	Post q;
	ifstream post("Forum.bin", ios::binary | ios::in);
	if (post.is_open()){
		post.read((char *)(&q), sizeof(Post));
		post.close();
	}
}
*/
Post::~Post()
{
}
