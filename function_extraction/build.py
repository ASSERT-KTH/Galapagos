import asyncio
import os
import sys
from scripts.usecases.case import LibraryCompilableUseCase

DIRNAME = os.path.abspath(os.path.dirname(__file__))
LIBRARY = sys.argv[1] # TODO: check if this is correct, check if str() is needed

if __name__ == "__main__":
    async def main():
        project_folder = f"../use_cases/{LIBRARY}"
        project_folder = os.path.join(DIRNAME, project_folder)

        uc = LibraryCompilableUseCase(
            original_project_folder=project_folder,
            name=LIBRARY,
        )

        shadow_original = await uc.shadow(project_folder, name=f"{LIBRARY}")
        await uc.compile(shadow_original, configure_project=True)

        # Finally, we want to print the path where the project was built, for the other script to know where to look for it
        print(shadow_original)

    asyncio.run(main())
