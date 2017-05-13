#ifndef COMMAND_LINE_WIZ_HPP
#define COMMAND_LINE_WIZ_HPP

#include <string>
#include <vector>
#include <memory>

/*
*=======================================================================================
*CommandLineWizクラス
*コマンドラインを処理するクラス
*=======================================================================================
*/
class CommandLineWiz {
private:
	//もともとのコマンドを保持するメンバ
	std::unique_ptr<std::string> origin;

	//コマンドを分割して保持するメンバ
	std::unique_ptr<std::vector<std::string>> word_vector;

public:
	/*
	*コンストラクタ
	*引数に文字列ありと文字列なしを用意
	*/
	CommandLineWiz();
	CommandLineWiz(const char *command_line);

	//デストラクタ
	~CommandLineWiz();

	//word_vectorの中身を取り出すメソッド
	std::string At(int index);
	void Reset(const char *command_line);
};

#endif