#ifndef COMMAND_LINE_WIZ_HPP
#define COMMAND_LINE_WIZ_HPP

#include <string>
#include <vector>
#include <memory>

/*
*=======================================================================================
*CommandLineWiz�N���X
*�R�}���h���C������������N���X
*=======================================================================================
*/
class CommandLineWiz {
private:
	//���Ƃ��Ƃ̃R�}���h��ێ����郁���o
	std::unique_ptr<std::string> origin;

	//�R�}���h�𕪊����ĕێ����郁���o
	std::unique_ptr<std::vector<std::string>> word_vector;

public:
	/*
	*�R���X�g���N�^
	*�����ɕ����񂠂�ƕ�����Ȃ���p��
	*/
	CommandLineWiz();
	CommandLineWiz(const char *command_line);

	//�f�X�g���N�^
	~CommandLineWiz();

	//word_vector�̒��g�����o�����\�b�h
	std::string At(int index);
	void Reset(const char *command_line);
};

#endif