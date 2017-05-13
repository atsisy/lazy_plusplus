#include "cmdline_wiz.hpp"
#include <sstream>
#include <memory>

/*
*=======================================================================================
*str_shrink�֐�
*�����񒆂̎w�肵�������񂪘A���ŏo�������ꍇ�A��������k����֐�
*std::unique_ptr<std::string> str
*�Ώۂ̕�����ւ̃X�}�[�g�|�C���^
*short index
*�ǂ����猟�����n�߂邩
*char target
*�������镶��
*�Ԃ�l
*������̕�����̃X�}�[�g�|�C���^
*=======================================================================================
*/
static std::unique_ptr<std::string> str_shrink(std::unique_ptr<std::string> str, short index, char target, bool flag = false) {

	for (unsigned short i = index; i < str->length(); ++i) {
		//�^�[�Q�b�g�̕������H
		if (str->data()[i] == target) {
			if (!flag) {
				//�܂�����
				flag = true;
			}
			else {
				//���A���ŏo�Ă�����ꕶ���i�߂čċA����
				str = str_shrink(std::move(str), i + 1, target, flag);
				//�ċA����߂��Ă��������
				str->erase(str->begin() + i);
			}
		}
		else {
			//��{�I�ɂ̓t���O��false�ɐݒ�
			flag = false;
		}
	}
	return str;
}

/*
*=======================================================================================
*�R���X�g���N�^
*�����Ȃ�
*�����o�I�u�W�F�N�g�𐶐����邾��
*=======================================================================================
*/
CommandLineWiz::CommandLineWiz()
	: origin(nullptr), word_vector(nullptr)
{
	/*
	*�����o�I�u�W�F�N�g�𐶐����邾��
	*/
}

/*
*=======================================================================================
*�R���X�g���N�^
*����
*const char *command_line
*��������R�}���h
*�R�}���h�𕪊����āAword_vector�ɂԂ�����
*=======================================================================================
*/
CommandLineWiz::CommandLineWiz(const char *command_line) {
	Reset(command_line);
}

/*
*=======================================================================================
*�f�X�g���N�^
*=======================================================================================
*/
CommandLineWiz::~CommandLineWiz() {
	origin.reset(nullptr);
	word_vector.reset(nullptr);
}

/*
*=======================================================================================
*CommandLineWiz::At���\�b�h
*�R�}���h���C����index�Ԗڂ̕������Ԃ��֐�
*����
*int index
*�C���f�b�N�X
*�Ԃ�l
*������
*=======================================================================================
*/
std::string CommandLineWiz::At(int index) {
	//vector�̒l�����ĕԂ�����
	return word_vector->at(index);
}

/*
*=======================================================================================
*CommandLineWiz::Reset���\�b�h
*����
*const char *command_line
*�Đݒ�p�̕�����
*�Ԃ�l
*�Ȃ�
*=======================================================================================
*/
void CommandLineWiz::Reset(const char *command_line) {

	word_vector.reset(new std::vector<std::string>);

	//������̐擪���X�y�[�X�ɂȂ�̂�h��
	while (*command_line == ' ') ++command_line;

	//�擪�̃X�y�[�X������Aorigin��ݒ�
	origin.reset(new std::string(command_line));

	//StringStream�N���X���g���ď�������
	std::stringstream string_stream(command_line);
	//�ꎞ�I�Ɏg��������ϐ�
	std::string buffer;

	//��������ߒ��Ŏז��ɂȂ�A���X�y�[�X�����k
	origin = str_shrink(std::move(origin), 0, ' ');

	//�����ŕ������āAword_vector�ɂԂ�����
	while (std::getline(string_stream, buffer, ' ')) {
		word_vector->push_back(buffer);
	}

}