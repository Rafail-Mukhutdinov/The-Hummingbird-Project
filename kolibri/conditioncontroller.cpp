#include "conditioncontroller.h"


ConditionController::ConditionController()
{

}

bool ConditionController::checkLineEditNotEmpty (Ui::MainWindow *cui, const ParamFormMain &paramLineEdit)
{
    bool check = true;
    QString text_info;

    // Получил уникальные значение
    this->arrayOfFileTypesMask = textcont.getUniqueWords(paramLineEdit.inputMaskFile);
    QString textMaskInfo = arrayOfFileTypesMask.join(" ");
    cui->lineEdit_mask_file->setText(textMaskInfo);

    QString trimmedInputMaskFile = paramLineEdit.inputMaskFile.trimmed();
    QString trimmedInputDirStart = paramLineEdit.inputDirStart.trimmed();
    QString trimmedOutputDirFinish = paramLineEdit.outputDirFinish.trimmed();
    QString trimmedInputMaskXor = paramLineEdit.inputMaskXor.trimmed();

    if(trimmedInputMaskFile.isEmpty() || arrayOfFileTypesMask.empty())
    {
        text_info += "Введите корректную маску файла.\n";
        check = false;
    }
    if(!this->isDirectoryValid(trimmedInputDirStart))
    {
        text_info += "Выбирите корректную входную директорию.\n";
        check = false;
    }
    if(trimmedInputMaskXor.isEmpty())
    {
        text_info += "Введите XOR.\n";
        check = false;
    }
    if(!this->isDirectoryValid(trimmedOutputDirFinish))
    {
        text_info += "Выбирите корректную выходную директорию.\n";
        check = false;
    }
    if( !trimmedInputDirStart.isEmpty() &&
        !trimmedOutputDirFinish.isEmpty() &&
        trimmedInputDirStart == trimmedOutputDirFinish)
    {
        text_info += "Входная и выходная директория не должны совпадать.\n";
        check = false;
    }
    if(!check)
    {
        cui->label_Text_info->setText(text_info);
    }
    return check;
}

bool ConditionController::isDirectoryValid(const QString &paramDir)
{
    return !paramDir.trimmed().isEmpty() && QDir(paramDir).exists();
}



