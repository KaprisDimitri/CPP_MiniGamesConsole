// std::move(objet)
// Cette fonction permet de retourner le contenu de l'objet et pas une copie.
// Exmple:
// std::vector<int> source = {1, 2, 3};
// std::vector<int> destination = std::move(source);
// Maintenant, source est vide, et destination contient {1, 2, 3}

// std::promise<Type>
// c est un objet qui contient une valeur. Celle ci peut etre recuperer par "std::future<Type>"
// std::future<Type>
// c'est un objet qui peut recupérer la valeur de l'objet promise
// Exemple:
// std::promise<int> promise; // Cree l'objet promise de type int
// std::future<int> future = promise.get_future(); //  Cree l'objet future de type int. reference l'objet promise.
// promise.setalue(50); // Set valeur dans promise
// int value = future.get(); // attend que la valeur soit prete pour la recuperer

// std::future_status status
// C est une enum qui renvoie les 3 etat possible de la fonction future.wait_for();
// future.wait_for(durer d att);
// Cette fonction permet d'attendre une durer determiner de type std::chrono::duration. Si la valeur a changer avant la fin de la duree, le programme continue.
// Exemple:
// std::future_status status = future.wait_for(std::chrono::seconds(1));
// if (status == std::future_status::ready) // Le futur est prêt, récupérez la valeur 
// int value = future.get();

// std::this_thread::sleep_for()
// Cette fonction permet de couper le programme pendant un temps donner. Prend std::chrono::duration comme entrer

// [] { YO(); }
// declaration de delegate lambda
// [] || [&] ||[=]  &par reference =par valeur

// std::atomic<Type>
// type qui peut etre lu et reecrit par tout les thread sans qu il y est de conflit

// _getch();
// permet d'attendre un Input de l utilisateur sans qu il est a cliquer sur entrer