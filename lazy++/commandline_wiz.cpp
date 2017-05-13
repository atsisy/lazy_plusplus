#include "cmdline_wiz.hpp"
#include <sstream>
#include <memory>

/*
*=======================================================================================
*str_shrink関数
*文字列中の指定した文字列が連続で出現した場合、それを圧縮する関数
*std::unique_ptr<std::string> str
*対象の文字列へのスマートポインタ
*short index
*どこから検索を始めるか
*char target
*検索する文字
*返り値
*処理後の文字列のスマートポインタ
*=======================================================================================
*/
static std::unique_ptr<std::string> str_shrink(std::unique_ptr<std::string> str, short index, char target, bool flag = false) {

	for (unsigned short i = index; i < str->length(); ++i) {
		//ターゲットの文字か？
		if (str->data()[i] == target) {
			if (!flag) {
				//まだ一回目
				flag = true;
			}
			else {
				//二回連続で出てきたら一文字進めて再帰処理
				str = str_shrink(std::move(str), i + 1, target, flag);
				//再帰から戻ってきたら消す
				str->erase(str->begin() + i);
			}
		}
		else {
			//基本的にはフラグをfalseに設定
			flag = false;
		}
	}
	return str;
}

/*
*=======================================================================================
*コンストラクタ
*引数なし
*メンバオブジェクトを生成するだけ
*=======================================================================================
*/
CommandLineWiz::CommandLineWiz()
	: origin(nullptr), word_vector(nullptr)
{
	/*
	*メンバオブジェクトを生成するだけ
	*/
}

/*
*=======================================================================================
*コンストラクタ
*引数
*const char *command_line
*処理するコマンド
*コマンドを分割して、word_vectorにぶち込む
*=======================================================================================
*/
CommandLineWiz::CommandLineWiz(const char *command_line) {
	Reset(command_line);
}

/*
*=======================================================================================
*デストラクタ
*=======================================================================================
*/
CommandLineWiz::~CommandLineWiz() {
	origin.reset(nullptr);
	word_vector.reset(nullptr);
}

/*
*=======================================================================================
*CommandLineWiz::Atメソッド
*コマンドラインのindex番目の文字列を返す関数
*引数
*int index
*インデックス
*返り値
*文字列
*=======================================================================================
*/
std::string CommandLineWiz::At(int index) {
	//vectorの値を見て返すだけ
	return word_vector->at(index);
}

/*
*=======================================================================================
*CommandLineWiz::Resetメソッド
*引数
*const char *command_line
*再設定用の文字列
*返り値
*なし
*=======================================================================================
*/
void CommandLineWiz::Reset(const char *command_line) {

	word_vector.reset(new std::vector<std::string>);

	//文字列の先頭がスペースになるのを防ぐ
	while (*command_line == ' ') ++command_line;

	//先頭のスペース除去後、originを設定
	origin.reset(new std::string(command_line));

	//StringStreamクラスを使って処理する
	std::stringstream string_stream(command_line);
	//一時的に使う文字列変数
	std::string buffer;

	//処理する過程で邪魔になる連続スペースを圧縮
	origin = str_shrink(std::move(origin), 0, ' ');

	//ここで分割して、word_vectorにぶち込む
	while (std::getline(string_stream, buffer, ' ')) {
		word_vector->push_back(buffer);
	}

}