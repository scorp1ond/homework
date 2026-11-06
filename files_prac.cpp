#include <iostream>

const int MAX_LINES = 100;
const int MAX_LENGTH = 256;

int textLength(const char text[]) {
	int length = 0;
	while (text[length] != '\0') {
		length++;
	}
	return length;
}

bool containsSpace(const char text[]) {
	int i = 0;
	while (text[i] != '\0') {
		if (text[i] == ' ') {
			return true;
		}
		i++;
	}
	return false;
}

bool endsWithNewline(const char text[]) {
	int length = textLength(text);
	return length > 0 && text[length - 1] == '\n';
}

bool openFiles(FILE*& input, FILE*& output) {
	if (fopen_s(&input, "input.txt", "r")) {
		std::cout << "Cannot open input.txt\n";
		return false;
	}

	if (fopen_s(&output, "output.txt", "w")) {
		std::cout << "Cannot create output.txt\n";
		fclose(input);
		return false;
	}

	return true;
}

void task1() {
	FILE* input = nullptr;
	FILE* output = nullptr;
	if (!openFiles(input, output)) return;

	char word[MAX_LENGTH];
	while (fscanf_s(input, "%255s", word, MAX_LENGTH) == 1) {
		if (textLength(word) >= 7) {
			fprintf_s(output, "%s\n", word);
		}
	}

	fclose(input);
	fclose(output);
}

void task2() {
	FILE* input = nullptr;
	FILE* output = nullptr;
	if (!openFiles(input, output)) return;

	char line[MAX_LENGTH];
	while (fgets(line, MAX_LENGTH, input) != nullptr) {
		fprintf_s(output, "%s", line);
	}

	fclose(input);
	fclose(output);
}

void task3() {
	FILE* input = nullptr;
	FILE* output = nullptr;
	if (!openFiles(input, output)) return;

	char lines[MAX_LINES][MAX_LENGTH];
	int lineCount = 0;

	while (lineCount < MAX_LINES &&
		fgets(lines[lineCount], MAX_LENGTH, input) != nullptr) {
		lineCount++;
	}

	for (int i = lineCount - 1; i >= 0; i--) {
		fprintf_s(output, "%s", lines[i]);
		if (!endsWithNewline(lines[i])) {
			fprintf_s(output, "\n");
		}
	}

	fclose(input);
	fclose(output);
}

void task4() {
	FILE* input = nullptr;
	FILE* output = nullptr;
	if (!openFiles(input, output)) return;

	char lines[MAX_LINES][MAX_LENGTH];
	int lineCount = 0;
	int lastWithoutSpaces = -1;

	while (lineCount < MAX_LINES &&
		fgets(lines[lineCount], MAX_LENGTH, input) != nullptr) {
		if (!containsSpace(lines[lineCount])) {
			lastWithoutSpaces = lineCount;
		}
		lineCount++;
	}

	for (int i = 0; i < lineCount; i++) {
		fprintf_s(output, "%s", lines[i]);
		if (!endsWithNewline(lines[i])) {
			fprintf_s(output, "\n");
		}
		if (i == lastWithoutSpaces) {
			fprintf_s(output, "------------\n");
		}
	}

	if (lastWithoutSpaces == -1) {
		fprintf_s(output, "------------\n");
	}

	fclose(input);
	fclose(output);
}

int main() {
	int choice = 0;

	std::cout << "Choose task (1-4): ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	default:
		std::cout << "Incorrect task number\n";
		return 1;
	}

	std::cout << "Done. Result saved to output.txt\n";
	return 0;
}

