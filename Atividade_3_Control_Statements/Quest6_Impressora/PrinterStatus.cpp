#include "PrinterStatus.h"

PrinterStatus::PrinterStatus(unsigned char status)
{
	this->status = status;
}

unsigned char PrinterStatus::getStatus()
{
	return status;
}

bool PrinterStatus::printerOn()
{
	return (status & 0x01) != 0;
}

bool PrinterStatus::printerWithPaper()
{
	return (status & 0x02) != 0;
}

bool PrinterStatus::printerBufferFull()
{
	return (status & 0x04) != 0;
}

bool PrinterStatus::blackPrintCartridge()
{
	return (status & 0x06) != 0;
}

bool PrinterStatus::tricolorPrintCartridge()
{
	return (status & 0x08) != 0;
}


void test(unsigned status) {

	PrinterStatus printer(status);


	cout << "Status da Impressora:" << endl;
	cout << "Ligada: " << (printer.printerOn() ? "Sim" : "Não") << endl;
	cout << "Com Papel: " << (printer.printerWithPaper() ? "Sim" : "Não") << endl;
	cout << "Buffer: " << (printer.printerBufferFull() ? "livre" : "cheio") << endl;
	cout << "Cartucho de Tinta Preto: " << (printer.blackPrintCartridge() ? "Com Tinta" : "Vazio") << endl;
	cout << "Cartucho de Tinta Tricolor: " << (printer.tricolorPrintCartridge() ? "Com Tinta" : "Vazio") << endl;
}

int main() {
	char status;
	do
	{
		cout << "Status" << endl;
		cin >> status;

		if (status != '0')
		{
			test(status);
		}
	} while (status != '0');

	return 0;
}
