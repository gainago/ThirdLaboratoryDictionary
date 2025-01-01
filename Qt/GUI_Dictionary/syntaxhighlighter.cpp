#include "syntaxhighlighter.h"
#include "checkqstring.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{}

void SyntaxHighlighter::highlightBlock(const QString& str)
{
    if(!isNormalQString(str)){
        setFormat(0, str.size(), Qt::red);
    }
}
