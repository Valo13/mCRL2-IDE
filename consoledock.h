#ifndef CONSOLEDOCK_H
#define CONSOLEDOCK_H

#include <QDockWidget>
#include <QPlainTextEdit>
#include <QTabWidget>
#include <QProcess>

/**
 * @brief The ConsoleDock class defines the dock that shows console output
 */
class ConsoleDock : public QDockWidget
{
    Q_OBJECT

public:    
    const Qt::DockWidgetArea defaultArea = Qt::BottomDockWidgetArea;

    enum ConsoleTab {Parsing, LTSCreation, Verification};

    /**
     * @brief ConsoleDock Constructor
     * @param parent The parent of this widget
     */
    explicit ConsoleDock(QWidget *parent);

    /**
     * @brief setConsoleTab Set which tab should be visible
     * @param tab The tab to make visible
     */
    void setConsoleTab(ConsoleTab tab);

    /**
     * @brief writeToConsole Write something to the console
     * @param tab Which console tab to write to
     * @param output What to write
     */
    void writeToConsole(ConsoleTab tab, QString output);

public slots:
    /**
     * @brief logToConsole Write output in the parsing console
     */
    void logToParsingConsole();

    /**
     * @brief logToConsole Write output in the LTS creation console
     */
    void logToLTSCreationConsole();

    /**
     * @brief logToConsole Write output in the verification console
     */
    void logToVerificationConsole();

private:
    QTabWidget *consoleTabs;
    QPlainTextEdit *parsingConsole;
    QPlainTextEdit *LTSCreationConsole;
    QPlainTextEdit *verificationConsole;

    /**
     * @brief logToConsole Write output in the console
     * @param tab Which console tab to write to
     */
    void logToConsole(QPlainTextEdit *console, QProcess *process);
};

#endif // CONSOLEDOCK_H
