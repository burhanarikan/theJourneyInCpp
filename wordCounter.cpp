#include <iostream> // input-output stream
#include <fstream> // file stream

using namespace std; // std namespace tanımlandı

int main() { // ana fonksiyon
    
    string filePath, wordToFind, word;
    
    int wordCount = 0;

    // Kullanıcıdan dosya adı ve aranacak kelimeyi al
    cout << "Dosya yolunu girin: ";
    cin >> filePath;

    // Dosyayı aç
    ifstream inputFile(filePath);
    
    if (!inputFile) { // dosya açılamadıysa
        cerr << "Error: Could not open the file '" << filePath << "'." << endl; // hatayı belirt
        return 1;
    }
    
    cout << "Büyük harf ayrımına dikkat ederek (harfleri nasıl girerseniz sadece o şekildeki kelime bulunur. 'al' girerseniz 'Al' bulunmaz.) aranacak kelimeyi girin: ";
    cin >> wordToFind;

    // Kelimeyi say
    while (inputFile >> word) { // dosyadaki kelimeleri tek tek word değişkenine ata...
        if (word == wordToFind) { // atanan kelimenin, aranan kelimeye eşit olup olmadığına bak...
            wordCount++; // eşitse kelime wordCount'u 1 arttır
        }
    }

    inputFile.close(); // dosyayı kapat

    // Sonucu yazdır
    cout << "\"" << wordToFind << "\" kelimesi " << wordCount << " kez bulundu." << endl;

    cout << "File read successfully '" << filePath << "'. " << "Program completed." << endl; // programın başarıyla tamamlandığına dair çıktı ver.
    
    return 0;
}
