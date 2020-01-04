
// 现在随着社会的进步到了现代社会，人手一只手机，
// 每天就可以通过手机app来看各种各样的新闻，你也看我也看，张三看李四看。
// 只要app新闻一出来，任何关注这个app的手机都会收到新发布的新闻。

#include <iostream>
#include "IReader.h"
#include "INews.h"

using namespace std;

int main() {
	
    // Observer
	IReader* zhangsan = new TrueReader("张三");
	IReader* lisi = new TrueReader("李四");
	IReader* wangwu = new TrueReader("王五");

    // subject
	INews* news = new AppNews();

	news->addReader(zhangsan);
	news->addReader(lisi);
	news->addReader(wangwu);

    // 发布消息了
    cout << "======= app软件上发布消息了：春节放假十五天！=======" << endl;
	news->releaseNews("春节放假十五天！");

    cout << endl << "======= 王五 取消了订阅 =======" << endl << endl;
    news->delReader(wangwu);

    cout << "======= app软件上修改消息了：春节放假十天！=======" << endl;
    news->releaseNews("春节放假十天！");
	return 0;
}
